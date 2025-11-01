// testbench_elevador.v

[TESTE 1] Verificando Reset e Estado Inicial
----------------------------------------------------------------
[0 ns] Aplicando RESET...
[200 ns] Reset concluído. Elevador no térreo.
[300 ns] ✓ PASSOU: Elevador está no andar 0
[300 ns] ✓ PASSOU: 0 passageiros no elevador

========== STATUS DO ELEVADOR [300 ns] ==========
  Andar Atual: 0
  Subindo: 0 | Descendo: 0
  Porta Aberta: 0 | Beep: 0
  Lotado: 0 | Emergência: 0
===================================================


[TESTE 2] Requisição Simples - Subir ao 2º Andar
----------------------------------------------------------------
[500 ns] Requisitando andar 2
[5.5 ms] ✓ PASSOU: Elevador está no andar 2


[TESTE 3] Entrada e Saída de Passageiros
----------------------------------------------------------------
[6.5 ms] Pessoa entrando...
[6.6 ms] ✓ PASSOU: 1 passageiros no elevador
[6.7 ms] Pessoa entrando...
[6.8 ms] ✓ PASSOU: 2 passageiros no elevador
[6.9 ms] Pessoa saindo...
[7.0 ms] ✓ PASSOU: 1 passageiros no elevador

========== STATUS DO ELEVADOR [7.0 ms] ==========
  Andar Atual: 2
  Subindo: 0 | Descendo: 0
  Porta Aberta: 1 | Beep: 0
  Lotado: 0 | Emergência: 0
===================================================


[TESTE 4] Modo de Emergência
----------------------------------------------------------------
[8.0 ms] Requisitando andar 4
[13.0 ms] ✓ PASSOU: Elevador está no andar 4
[13.1 ms] *** EMERGÊNCIA ATIVADA ***
[23.1 ms] ✓ PASSOU: Elevador está no andar 0
[23.2 ms] ✓ PASSOU: Porta aberta no térreo


[TESTE 5] Teste de Lotação Máxima
----------------------------------------------------------------
[25.0 ms] Entrando 6 passageiros...
[25.6 ms] ✓ PASSOU: 6 passageiros no elevador
[25.7 ms] ✓ PASSOU: Indicador de lotação ativado (LEDR[8])
[25.8 ms] Tentando entrada extra (bloqueada)
[25.9 ms] ✓ PASSOU: Continua com 6 passageiros


[TESTE 6] Ignorar Requisição Direção Oposta
----------------------------------------------------------------
[27.0 ms] Requisitando andar 4 (subindo)
[27.5 ms] Durante subida, requisitando térreo (direção oposta)
[34.5 ms] ✓ PASSOU: Elevador chegou no andar 4
[44.5 ms] ✓ PASSOU: Elevador atendeu térreo após completar subida


================================================================================
                        RESUMO FINAL DOS TESTES
================================================================================
  Total de Testes: 6

  1. Reset e Estado Inicial .................. OK
  2. Requisição Simples - Subir .............. OK
  3. Entrada e Saída de Passageiros .......... OK
  4. Modo de Emergência ...................... OK
  5. Teste de Lotação Máxima ................. OK
  6. Ignorar Requisição Direção Oposta ....... OK

  Todos os testes passaram com sucesso.
  Simulação encerrada.
================================================================================

