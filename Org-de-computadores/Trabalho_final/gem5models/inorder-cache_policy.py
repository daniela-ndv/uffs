#
# Adaptado para o trabalho de "Politicas de Substituicao de Cache" (LRU vs Random)
# utilizando o modelo In-Order (TIMING) do gem5.
#
# Uso:
#   gem5.opt inorder.py --binary <bin> --policy lru    -d resultados_lru
#   gem5.opt inorder.py --binary <bin> --policy random -d resultados_random

import os
import argparse

import m5
from m5.objects import *
from m5.objects import LRURP, RandomRP

from gem5.components.boards.simple_board import SimpleBoard
from gem5.components.cachehierarchies.classic.private_l1_private_l2_cache_hierarchy import (
    PrivateL1PrivateL2CacheHierarchy,
)
from gem5.components.cachehierarchies.classic.caches.l1dcache import L1DCache
from gem5.components.cachehierarchies.classic.caches.l1icache import L1ICache
from gem5.components.cachehierarchies.classic.caches.l2cache import L2Cache
from gem5.components.memory.single_channel import SingleChannelDDR3_1600
from gem5.components.processors.cpu_types import CPUTypes
from gem5.components.processors.simple_processor import SimpleProcessor
from gem5.resources.resource import BinaryResource
from gem5.simulate.simulator import Simulator
from gem5.isas import ISA

parser = argparse.ArgumentParser()
parser.add_argument(
    "--binary",
    type=str,
    required=True,
    help="Caminho para binario RISC-V (estatico)",
)
parser.add_argument(
    "--policy",
    type=str,
    choices=["lru", "random"],
    default="lru",
    help="Politica de substituicao da cache L1D/L1I/L2 (default: lru)",
)
args = parser.parse_args()
binary_path = os.path.abspath(args.binary)

POLICY_MAP = {
    "lru": LRURP,
    "random": RandomRP,
}
policy_cls = POLICY_MAP[args.policy]

# Altera o valor PADRAO do parametro replacement_policy nas classes antes de criar a hierarquia.
L1DCache.replacement_policy = policy_cls()
L1ICache.replacement_policy = policy_cls()
L2Cache.replacement_policy = policy_cls()

print(f"Politica de substituicao configurada: {args.policy.upper()}")

# 1. Escolhemos o modelo In-Order (TIMING) para RISC-V
processor = SimpleProcessor(cpu_type=CPUTypes.TIMING, num_cores=1, isa=ISA.RISCV)

# 2. Configuração de Memória e Cache
cache_hierarchy = PrivateL1PrivateL2CacheHierarchy(
    l1d_size="32kB", l1i_size="32kB", l2_size="256kB"
)
memory = SingleChannelDDR3_1600("1GB")

# 3. Montagem da placa
board = SimpleBoard(
    clk_freq="3GHz",
    processor=processor,
    memory=memory,
    cache_hierarchy=cache_hierarchy,
)

# 5. Workload
binary = BinaryResource(local_path=binary_path)
board.set_se_binary_workload(binary)

# 6. Rodar a simulacao
simulator = Simulator(board=board)
print("Iniciando simulacao In-Order RISC-V...")
simulator.run()

print(f"Simulacao finalizada no tick {simulator.get_current_tick()}")