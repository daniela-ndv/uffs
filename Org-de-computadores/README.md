# Avaliação de Microarquitetura RISC-V com o Simulador gem5

**Disciplina:** Organização de Computadores  
**Tópico:** Políticas de Substituição de Cache (LRU vs Random)  
**Algoritmo:** QuickSort em assembly RISC-V  
**Autoras:** Daniela do Nascimento Dalla Vecchia e Elen Letícia Pereira

---

## Descrição

Este trabalho avalia o impacto de diferentes políticas de substituição de cache no desempenho de um algoritmo de ordenação (QuickSort) implementado em assembly RISC-V. A análise é realizada com o simulador **gem5**, comparando as políticas **LRU** (*Least Recently Used*) e **Random** sobre um processador In-Order (MinorCPU).

---

## Compilação

O binário deve ser gerado como **estático** para RISC-V de 64 bits:

```bash
riscv64-linux-gnu-gcc -o main.riscv -static main.s
```

> Certifique-se de ter o cross-compiler `riscv64-linux-gnu-gcc` instalado.  
> No Ubuntu/Debian: `sudo apt install gcc-riscv64-linux-gnu`

---

## Executando as Simulações

### Política LRU 

```bash
gem5.opt gem5models/inorder-cache_policy.py \
  --binary main.riscv \
  --policy lru \
  -d resultados_lru
```

### Política Random

```bash
gem5.opt gem5models/inorder-cache_policy.py \
  --binary main.riscv \
  --policy random \
  -d resultados_random
```

> Substitua `gem5.opt` pelo caminho completo do executável gem5 caso não esteja no `PATH`.

---

## Métricas Coletadas (dos arquivos `stats.txt`)

| Métrica | LRU | Random |
|---|---|---|
| Instruções simuladas (`simInsts`) | 40.860.572 | 132.685 |
| Ciclos totais (`numCycles`) | 14.783.755 | 99.869 |
| Tempo de simulação (`simTicks`) | 4.922.990.082 ps | 33.256.044 ps |
| IPC (`core.ipc`) | **2,76** | **1,33** |
| Misses na L1D (`overallMisses`) | 4.146 | 3.709 |
| Taxa de miss L1D (`overallMissRate`) | **0,03%** | **12,75%** |
| Latência média de miss L1D (ticks) | 26.935 | 26.993 |

### Principais métricas para extração manual

```bash
# IPC
grep "core.ipc" stats.txt

# Tempo de simulação
grep "simTicks" stats.txt

# Misses na cache de dados
grep "l1d-cache.*overallMisses::total" stats.txt

# Taxa de miss
grep "l1d-cache.*overallMissRate::total" stats.txt

# Total de instruções
grep "simInsts" stats.txt
```

---

## Dependências

- **gem5** (versão com suporte a RISC-V)
- `riscv64-linux-gnu-gcc` (cross-compiler)
- Python 3 (para os scripts de configuração do gem5)
