`timescale 1ns/1ps

module elevador(
    input  wire CLOCK_50,
    input  wire [3:0] KEY,
    input  wire [9:0] SW,
    output wire [9:0] LEDR,
    output wire [7:0] LEDG,
    output wire [6:0] HEX0,
    output wire [6:0] HEX1,
    output wire [6:0] HEX2,
    output wire [6:0] HEX3,
    output wire [6:0] HEX4,
    output wire [6:0] HEX5
);

    // ----------------------------
    // Parâmetros
    // ----------------------------
    parameter NUM_ANDARES = 5;
    parameter BITS_ANDAR = 3;
    parameter MAX_PESSOAS = 6;
    parameter ATRASO_MAX = 27'd25000000;
    parameter ATRASO_MOVIMENTO = 27'd100000000;

    // ----------------------------
    // Sinais internos
    // ----------------------------
    wire rst = ~KEY[0];
    wire emergencia = ~KEY[1];
    wire btn_entrar = ~KEY[2];
    wire btn_sair = ~KEY[3];
    wire [NUM_ANDARES-1:0] botoes_req = SW[NUM_ANDARES-1:0];

    // Debounce
    reg btn_entrar_anterior, btn_sair_anterior;
    wire btn_entrar_pulso = btn_entrar && !btn_entrar_anterior;
    wire btn_sair_pulso = btn_sair && !btn_sair_anterior;

    // Registradores principais
    reg [BITS_ANDAR-1:0] andar_atual;
    reg [2:0] estado;
    reg [26:0] contador_atraso;
    reg [3:0] cont_passageiros;
    reg [NUM_ANDARES-1:0] requisicoes_pendentes;
    reg flag_lotado;
    reg subindo, descendo, porta_aberta, beep_chegada;
    reg pessoa_saiu_neste_andar;
    reg porta_emergencia_aberta;

    // Estados
    localparam ST_OCIOSO = 3'd0;
    localparam ST_ABRINDO = 3'd1;
    localparam ST_ABERTA = 3'd2;
    localparam ST_FECHANDO = 3'd3;
    localparam ST_SUBINDO = 3'd4;
    localparam ST_DESCENDO = 3'd5;
    localparam ST_EMERG = 3'd6;
    localparam ST_EMERG_ABERTA = 3'd7;

    // ----------------------------
    // Funções
    // ----------------------------
    function [BITS_ANDAR-1:0] encontrar_andar_mais_proximo;
        input [NUM_ANDARES-1:0] reqs;
        input [BITS_ANDAR-1:0] andar;
        reg [BITS_ANDAR-1:0] distancia_minima;
        reg [BITS_ANDAR-1:0] mais_proximo;
        reg [BITS_ANDAR-1:0] distancia;
        integer i;
        begin
            distancia_minima = NUM_ANDARES;
            mais_proximo = andar;
            
            for (i = 0; i < NUM_ANDARES; i = i + 1) begin
                if (reqs[i]) begin
                    distancia = (i > andar) ? (i - andar) : (andar - i);
                    if (distancia < distancia_minima) begin
                        distancia_minima = distancia;
                        mais_proximo = i;
                    end
                end
            end
            encontrar_andar_mais_proximo = mais_proximo;
        end
    endfunction

    function requisicoes_acima;
        input [NUM_ANDARES-1:0] reqs;
        input [BITS_ANDAR-1:0] andar;
        integer i;
        begin
            requisicoes_acima = 1'b0;
            for (i = 0; i < NUM_ANDARES; i = i + 1) begin
                if ((i > andar) && reqs[i]) begin
                    requisicoes_acima = 1'b1;
                end
            end
        end
    endfunction

    function requisicoes_abaixo;
        input [NUM_ANDARES-1:0] reqs;
        input [BITS_ANDAR-1:0] andar;
        integer i;
        begin
            requisicoes_abaixo = 1'b0;
            for (i = 0; i < NUM_ANDARES; i = i + 1) begin
                if ((i < andar) && reqs[i]) begin
                    requisicoes_abaixo = 1'b1;
                end
            end
        end
    endfunction

    // ----------------------------
    // Debounce
    // ----------------------------
    always @(posedge CLOCK_50 or posedge rst) begin
        if (rst) begin
            btn_entrar_anterior <= 1'b0;
            btn_sair_anterior <= 1'b0;
        end else begin
            btn_entrar_anterior <= btn_entrar;
            btn_sair_anterior <= btn_sair;
        end
    end

    // ----------------------------
    // FSM Principal
    // ----------------------------
    always @(posedge CLOCK_50 or posedge rst) begin : BLOCO_FSM
        reg [BITS_ANDAR-1:0] mais_proximo;
        integer idx;
        
        if (rst) begin
            andar_atual <= 3'd0;
            estado <= ST_OCIOSO;
            contador_atraso <= 27'd0;
            cont_passageiros <= 4'd0;
            requisicoes_pendentes <= 5'b00000;
            subindo <= 1'b0;
            descendo <= 1'b0;
            porta_aberta <= 1'b0;
            beep_chegada <= 1'b0;
            flag_lotado <= 1'b0;
            pessoa_saiu_neste_andar <= 1'b0;
            porta_emergencia_aberta <= 1'b0;
        end else begin
            // Incrementa contador
            contador_atraso <= contador_atraso + 27'd1;

            // Acumula requisições
            if (!emergencia) begin
                if (subindo || descendo) begin
                    if (!flag_lotado) begin
                        if (subindo) begin
                            for (idx = 0; idx < NUM_ANDARES; idx = idx + 1) begin
                                if ((idx > andar_atual) && botoes_req[idx]) begin
                                    requisicoes_pendentes[idx] <= 1'b1;
                                end
                            end
                        end else if (descendo) begin
                            for (idx = 0; idx < NUM_ANDARES; idx = idx + 1) begin
                                if ((idx < andar_atual) && botoes_req[idx]) begin
                                    requisicoes_pendentes[idx] <= 1'b1;
                                end
                            end
                        end
                    end
                end else begin
                    requisicoes_pendentes <= requisicoes_pendentes | botoes_req;
                end
            end

            // Atualiza flag lotação
            flag_lotado <= (cont_passageiros >= MAX_PESSOAS);

            // Máquina de estados
            case (estado)
                ST_OCIOSO: begin
                    subindo <= 1'b0;
                    descendo <= 1'b0;
                    porta_aberta <= 1'b0;
                    beep_chegada <= 1'b0;
                    pessoa_saiu_neste_andar <= 1'b0;

                    if (emergencia) begin
                        requisicoes_pendentes <= 5'b00000;
                        estado <= ST_EMERG;
                        contador_atraso <= 27'd0;
                        porta_emergencia_aberta <= 1'b0;
                    end else if (requisicoes_pendentes[andar_atual]) begin
                        requisicoes_pendentes[andar_atual] <= 1'b0;
                        estado <= ST_ABRINDO;
                        contador_atraso <= 27'd0;
                    end else if (requisicoes_pendentes != 5'b00000) begin
                        mais_proximo = encontrar_andar_mais_proximo(requisicoes_pendentes, andar_atual);
                        
                        if (mais_proximo > andar_atual) begin
                            estado <= ST_SUBINDO;
                            contador_atraso <= 27'd0;
                        end else if (mais_proximo < andar_atual) begin
                            estado <= ST_DESCENDO;
                            contador_atraso <= 27'd0;
                        end
                    end
                end

                ST_ABRINDO: begin
                    porta_aberta <= 1'b1;
                    subindo <= 1'b0;
                    descendo <= 1'b0;
                    beep_chegada <= 1'b1;
                    pessoa_saiu_neste_andar <= 1'b0;
                    
                    if (contador_atraso >= ATRASO_MAX) begin
                        estado <= ST_ABERTA;
                        contador_atraso <= 27'd0;
                    end
                end

                ST_ABERTA: begin
                    porta_aberta <= 1'b1;
                    beep_chegada <= 1'b1;

                    if (btn_sair_pulso && (cont_passageiros > 0)) begin
                        cont_passageiros <= cont_passageiros - 4'd1;
                        pessoa_saiu_neste_andar <= 1'b1;
                    end

                    if (btn_entrar_pulso && (cont_passageiros < MAX_PESSOAS)) begin
                        cont_passageiros <= cont_passageiros + 4'd1;
                    end

                    if (contador_atraso >= ATRASO_MAX && !emergencia) begin
                        estado <= ST_FECHANDO;
                        contador_atraso <= 27'd0;
                    end
                end

                ST_FECHANDO: begin
                    porta_aberta <= 1'b0;
                    beep_chegada <= 1'b0;
                    
                    if (contador_atraso >= ATRASO_MAX) begin
                        contador_atraso <= 27'd0;
                        pessoa_saiu_neste_andar <= 1'b0;
                        
                        if (emergencia) begin
                            requisicoes_pendentes <= 5'b00000;
                            estado <= ST_EMERG;
                            porta_emergencia_aberta <= 1'b0;
                        end else if (requisicoes_pendentes != 5'b00000) begin
                            mais_proximo = encontrar_andar_mais_proximo(requisicoes_pendentes, andar_atual);
                            
                            if (mais_proximo > andar_atual) begin
                                estado <= ST_SUBINDO;
                            end else if (mais_proximo < andar_atual) begin
                                estado <= ST_DESCENDO;
                            end else begin
                                estado <= ST_OCIOSO;
                            end
                        end else begin
                            estado <= ST_OCIOSO;
                        end
                    end
                end

                ST_SUBINDO: begin
                    subindo <= 1'b1;
                    descendo <= 1'b0;
                    porta_aberta <= 1'b0;
                    beep_chegada <= 1'b0;

                    if (emergencia) begin
                        requisicoes_pendentes <= 5'b00000;
                        estado <= ST_EMERG;
                        contador_atraso <= 27'd0;
                        porta_emergencia_aberta <= 1'b0;
                    end else if (contador_atraso >= ATRASO_MOVIMENTO) begin
                        contador_atraso <= 27'd0;
                        
                        if (andar_atual < (NUM_ANDARES - 1))
                            andar_atual <= andar_atual + 3'd1;

                        if (andar_atual < (NUM_ANDARES - 1) && requisicoes_pendentes[andar_atual + 3'd1]) begin
                            requisicoes_pendentes[andar_atual + 3'd1] <= 1'b0;
                            estado <= ST_ABRINDO;
                        end else begin
                            if (requisicoes_acima(requisicoes_pendentes, andar_atual)) begin
                                estado <= ST_SUBINDO;
                            end else if (requisicoes_abaixo(requisicoes_pendentes, andar_atual)) begin
                                estado <= ST_DESCENDO;
                            end else begin
                                estado <= ST_OCIOSO;
                            end
                        end
                    end
                end

                ST_DESCENDO: begin
                    descendo <= 1'b1;
                    subindo <= 1'b0;
                    porta_aberta <= 1'b0;
                    beep_chegada <= 1'b0;

                    if (emergencia) begin
                        requisicoes_pendentes <= 5'b00000;
                        estado <= ST_EMERG;
                        contador_atraso <= 27'd0;
                        porta_emergencia_aberta <= 1'b0;
                    end else if (contador_atraso >= ATRASO_MOVIMENTO) begin
                        contador_atraso <= 27'd0;
                        
                        if (andar_atual > 0)
                            andar_atual <= andar_atual - 3'd1;

                        if (andar_atual > 0 && requisicoes_pendentes[andar_atual - 3'd1]) begin
                            requisicoes_pendentes[andar_atual - 3'd1] <= 1'b0;
                            estado <= ST_ABRINDO;
                        end else begin
                            if (requisicoes_abaixo(requisicoes_pendentes, andar_atual)) begin
                                estado <= ST_DESCENDO;
                            end else if (requisicoes_acima(requisicoes_pendentes, andar_atual)) begin
                                estado <= ST_SUBINDO;
                            end else begin
                                estado <= ST_OCIOSO;
                            end
                        end
                    end
                end

                ST_EMERG: begin
                    subindo <= 1'b0;
                    beep_chegada <= 1'b0;
                    flag_lotado <= 1'b0;
                    requisicoes_pendentes <= 5'b00000;
                    pessoa_saiu_neste_andar <= 1'b0;

                    if (andar_atual > 0) begin
                        porta_aberta <= 1'b0;
                        descendo <= 1'b1;
                        if (contador_atraso >= ATRASO_MOVIMENTO) begin
                            andar_atual <= andar_atual - 3'd1;
                            contador_atraso <= 27'd0;
                        end
                    end else begin
                        descendo <= 1'b0;
                        
                        if (!porta_emergencia_aberta) begin
                            porta_aberta <= 1'b1;
                            beep_chegada <= 1'b1;
                            porta_emergencia_aberta <= 1'b1;
                            estado <= ST_EMERG_ABERTA;
                            contador_atraso <= 27'd0;
                        end
                    end
                end

                ST_EMERG_ABERTA: begin
                    porta_aberta <= 1'b1;
                    beep_chegada <= 1'b1;
                    subindo <= 1'b0;
                    descendo <= 1'b0;
                    
                    if (btn_sair_pulso && (cont_passageiros > 0)) begin
                        cont_passageiros <= cont_passageiros - 4'd1;
                    end
                    
                    if (!emergencia) begin
                        if (contador_atraso >= ATRASO_MAX) begin
                            estado <= ST_FECHANDO;
                            contador_atraso <= 27'd0;
                            porta_emergencia_aberta <= 1'b0;
                        end
                    end
                end

                default: estado <= ST_OCIOSO;
            endcase
        end
    end

    // ----------------------------
    // Saídas LEDR
    // ----------------------------
    reg [9:0] ledr_r;
    always @(*) begin
        integer i;
        ledr_r = 10'd0;
        for (i = 0; i < NUM_ANDARES; i = i + 1) begin
            if (andar_atual == i)
                ledr_r[i] = 1'b1;
        end
        ledr_r[5] = subindo;
        ledr_r[6] = descendo;
        ledr_r[7] = porta_aberta;
        ledr_r[8] = flag_lotado;
        ledr_r[9] = beep_chegada;
    end
    assign LEDR = ledr_r;

    // ----------------------------
    // Display 7 segmentos
    // ----------------------------
    function [6:0] hex7seg;
        input [3:0] v;
        begin
            case (v)
                4'h0: hex7seg = 7'b1000000;
                4'h1: hex7seg = 7'b1111001;
                4'h2: hex7seg = 7'b0100100;
                4'h3: hex7seg = 7'b0110000;
                4'h4: hex7seg = 7'b0011001;
                4'h5: hex7seg = 7'b0010010;
                4'h6: hex7seg = 7'b0000010;
                4'h7: hex7seg = 7'b1111000;
                4'h8: hex7seg = 7'b0000000;
                4'h9: hex7seg = 7'b0010000;
                4'hA: hex7seg = 7'b0001000;
                4'hB: hex7seg = 7'b0000011;
                4'hC: hex7seg = 7'b1000110;
                4'hD: hex7seg = 7'b0100001;
                4'hE: hex7seg = 7'b0000110;
                4'hF: hex7seg = 7'b0001110;
                default: hex7seg = 7'b1111111;
            endcase
        end
    endfunction

    assign HEX0 = hex7seg({1'b0, andar_atual});
    assign HEX1 = hex7seg(cont_passageiros);
    assign HEX2 = 7'b1111111;
    assign HEX3 = 7'b1111111;
    assign HEX4 = 7'b1111111;
    assign HEX5 = 7'b1111111;

    // ----------------------------
    // LEDs Verdes
    // ----------------------------
    assign LEDG[0] = emergencia;
    assign LEDG[7:1] = 7'b0000000;

endmodule