`timescale 1ns/1ps

module testbench_elevador;

    // ----------------------------
    // Sinais de Entrada (reg)
    // ----------------------------
    reg CLOCK_50;
    reg [3:0] KEY;
    reg [9:0] SW;


    // ----------------------------
    // Sinais de Saída (wire)
    // ----------------------------
    wire [9:0] LEDR;
    wire [7:0] LEDG;
    wire [6:0] HEX0;
    wire [6:0] HEX1;
    wire [6:0] HEX2;
    wire [6:0] HEX3;
    wire [6:0] HEX4;
    wire [6:0] HEX5;


    // ----------------------------
    // Instanciação 
    // ----------------------------
    elevador uut (
        .CLOCK_50(CLOCK_50),
        .KEY(KEY),
        .SW(SW),
        .LEDR(LEDR),
        .LEDG(LEDG),
        .HEX0(HEX0),
        .HEX1(HEX1),
        .HEX2(HEX2),
        .HEX3(HEX3),
        .HEX4(HEX4),
        .HEX5(HEX5)
    );


    // ----------------------------
    // Geração do Clock (50MHz)
    // ----------------------------
    always #10 CLOCK_50 = ~CLOCK_50;


    // ----------------------------
    // Função auxiliar para decodificar display
    // ----------------------------
    function [3:0] decode_hex;
        input [6:0] hex;
        begin
            case (hex)
                7'b1000000: decode_hex = 4'h0;
                7'b1111001: decode_hex = 4'h1;
                7'b0100100: decode_hex = 4'h2;
                7'b0110000: decode_hex = 4'h3;
                7'b0011001: decode_hex = 4'h4;
                7'b0010010: decode_hex = 4'h5;
                7'b0000010: decode_hex = 4'h6;
                7'b1111000: decode_hex = 4'h7;
                7'b0000000: decode_hex = 4'h8;
                7'b0010000: decode_hex = 4'h9;
                default: decode_hex = 4'hF;
            endcase
        end
    endfunction


    // ----------------------------
    // Monitor Contínuo
    // ----------------------------
    always @(posedge CLOCK_50) begin
        if ($time > 100) begin
            $display("[%0t] Andar=%0d | Pass=%0d | Subindo=%b | Descendo=%b | Porta=%b | Lotado=%b | Beep=%b | Emerg=%b", 
                     $time/1000, decode_hex(HEX0), decode_hex(HEX1),
                     LEDR[5], LEDR[6], LEDR[7], LEDR[8], LEDR[9], LEDG[0]);
        end
    end


    // ----------------------------
    // Tarefas Auxiliares
    // ----------------------------
    
    // Tarefa para pressionar botão
    task pressionar_botao;
        input [1:0] botao; // 0=reset, 1=emerg, 2=entrar, 3=sair
        begin
            KEY[botao] = 0;
            #50_000_000; // 50ms
            KEY[botao] = 1;
            #50_000_000; // 50ms
        end
    endtask


    // Tarefa para requisitar andar
    task requisitar_andar;
        input [4:0] andar;
        begin
            SW[andar] = 1;
            #100;
            SW[andar] = 0;
        end
    endtask


    // Tarefa para aguardar movimento completo
    task aguardar_movimento;
        input integer ciclos;
        begin
            #(ciclos * 20); // 20ns por ciclo de clock
        end
    endtask


    // ----------------------------
    // Sequência de Testes
    // ----------------------------
    initial begin
        $display("\n========================================");
        $display("  TESTBENCH DO ELEVADOR - INICIO");
        $display("========================================\n");


        // Gera arquivo VCD para GTKWave
        $dumpfile("elevador_tb.vcd");
        $dumpvars(0, testbench_elevador);


        // Inicialização
        CLOCK_50 = 0;
        KEY = 4'b1111;      // Nenhum botão pressionado
        SW = 10'b0000000000; // Nenhuma requisição
        #100;


        // ========================================
        // TESTE 1: RESET
        // ========================================
        $display("\n=== TESTE 1: RESET ===");
        KEY[0] = 0; // Ativa reset
        #200;
        KEY[0] = 1; // Desativa reset
        #1000;
        $display("Reset concluido - Elevador no andar %0d", decode_hex(HEX0));


        // ========================================
        // TESTE 2: REQUISIÇÃO ANDAR 3
        // ========================================
        $display("\n=== TESTE 2: REQUISICAO ANDAR 3 ===");
        SW[3] = 1;
        aguardar_movimento(200_000_000); // ~4s
        SW[3] = 0;
        $display("Elevador chegou ao andar %0d", decode_hex(HEX0));
        aguardar_movimento(50_000_000); // Aguarda porta fechar


        // ========================================
        // TESTE 3: ENTRADA DE PASSAGEIROS
        // ========================================
        $display("\n=== TESTE 3: ENTRADA DE PASSAGEIROS ===");
        SW[2] = 1; // Vai ao andar 2
        aguardar_movimento(150_000_000);
        SW[2] = 0;
        
        $display("Entrando 3 passageiros...");
        repeat(3) begin
            pressionar_botao(2); // Botão entrar
        end
        aguardar_movimento(100_000_000);
        $display("Total de passageiros: %0d", decode_hex(HEX1));


        // ========================================
        // TESTE 4: SAÍDA DE PASSAGEIROS
        // ========================================
        $display("\n=== TESTE 4: SAIDA DE PASSAGEIROS ===");
        SW[0] = 1; // Vai ao térreo
        aguardar_movimento(200_000_000);
        SW[0] = 0;
        
        $display("Saindo 1 passageiro...");
        pressionar_botao(3); // Botão sair
        aguardar_movimento(50_000_000);
        $display("Total de passageiros: %0d", decode_hex(HEX1));
        aguardar_movimento(100_000_000);


        // ========================================
        // TESTE 5: TESTE DE LOTAÇÃO
        // ========================================
        $display("\n=== TESTE 5: TESTE DE LOTACAO ===");
        SW[1] = 1; // Vai ao andar 1
        aguardar_movimento(150_000_000);
        SW[1] = 0;
        
        $display("Enchendo o elevador (6 passageiros)...");
        repeat(6) begin
            pressionar_botao(2); // Botão entrar
        end
        aguardar_movimento(50_000_000);
        $display("Lotacao ativa: %b | Total passageiros: %0d", LEDR[8], decode_hex(HEX1));
        
        $display("Tentando adicionar mais um passageiro (deve falhar)...");
        pressionar_botao(2);
        aguardar_movimento(50_000_000);
        $display("Total passageiros apos tentativa: %0d", decode_hex(HEX1));
        aguardar_movimento(100_000_000);


        // ========================================
        // TESTE 6: MÚLTIPLAS REQUISIÇÕES
        // ========================================
        $display("\n=== TESTE 6: MULTIPLAS REQUISICOES ===");
        $display("Requisitando andares 4, 2 e 1...");
        SW[4] = 1;
        SW[2] = 1;
        SW[1] = 1;
        aguardar_movimento(800_000_000); // Aguarda atender todas
        SW[4] = 0;
        SW[2] = 0;
        SW[1] = 0;
        $display("Todas requisicoes atendidas");


        // ========================================
        // TESTE 7: MODO EMERGÊNCIA
        // ========================================
        $display("\n=== TESTE 7: MODO EMERGENCIA ===");
        SW[3] = 1; // Requisita andar 3
        aguardar_movimento(100_000_000); // Deixa começar a subir
        SW[3] = 0;
        
        $display("Ativando emergencia no andar %0d...", decode_hex(HEX0));
        KEY[1] = 0; // Ativa emergência
        aguardar_movimento(500_000_000); // Aguarda descida
        $display("Elevador chegou ao terreo em modo emergencia");
        $display("LED Emergencia: %b", LEDG[0]);
        aguardar_movimento(150_000_000); // Aguarda porta abrir


        // ========================================
        // TESTE 8: REQUISIÇÕES DURANTE MOVIMENTO
        // ========================================
        $display("\n=== TESTE 9: REQUISICOES DURANTE MOVIMENTO ===");
        $display("Indo para andar 4...");
        SW[4] = 1;
        aguardar_movimento(100_000_000); // Aguarda iniciar movimento
        
        $display("Requisitando andar 2 durante subida...");
        SW[2] = 1;
        aguardar_movimento(400_000_000);
        SW[4] = 0;
        SW[2] = 0;
        $display("Elevador no andar %0d", decode_hex(HEX0));
   

        // ========================================
        // FINALIZAÇÃO
        // ========================================
        aguardar_movimento(100_000_000);
        
        $display("\n========================================");
        $display("  TESTBENCH CONCLUIDO COM SUCESSO");
        $display("  Andar Final: %0d", decode_hex(HEX0));
        $display("  Passageiros Final: %0d", decode_hex(HEX1));
        $display("========================================\n");
        
        $finish;
    end

endmodule
