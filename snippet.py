
import sys
from collections import defaultdict


def input(): return sys.stdin.readline().rstrip()

"""

"""


T = int(input())
for _ in range(T):
    M, N, x, y = map(int, input().split())
    x -= 1
    y -= 1
    for t in range(0, M*N):
        print(f"{t} <{t%M},{t%N}>", end="\t")
        if t % M == 0:
            print()

"""
?) 아직도 의문인건, 분명 M,N의 카테시안 곱으로 존재할것 같은데..



1
10 12 7 2
0 <0,0>
1 <1,1>         2 <2,2>         3 <3,3>         4 <4,4>         5 <5,5>         6 <6,6>         7 <7,7>         8 <8,8>         9 <9,9>         10 <0,10>
11 <1,11>       12 <2,0>        13 <3,1>        14 <4,2>        15 <5,3>        16 <6,4>        17 <7,5>        18 <8,6>        19 <9,7>        20 <0,8>
21 <1,9>        22 <2,10>       23 <3,11>       24 <4,0>        25 <5,1>        26 <6,2>        27 <7,3>        28 <8,4>        29 <9,5>        30 <0,6>
31 <1,7>        32 <2,8>        33 <3,9>        34 <4,10>       35 <5,11>       36 <6,0>        37 <7,1>        38 <8,2>        39 <9,3>        40 <0,4>
41 <1,5>        42 <2,6>        43 <3,7>        44 <4,8>        45 <5,9>        46 <6,10>       47 <7,11>       48 <8,0>        49 <9,1>        50 <0,2>
51 <1,3>        52 <2,4>        53 <3,5>        54 <4,6>        55 <5,7>        56 <6,8>        57 <7,9>        58 <8,10>       59 <9,11>       60 <0,0>
61 <1,1>        62 <2,2>        63 <3,3>        64 <4,4>        65 <5,5>        66 <6,6>        67 <7,7>        68 <8,8>        69 <9,9>        70 <0,10>
71 <1,11>       72 <2,0>        73 <3,1>        74 <4,2>        75 <5,3>        76 <6,4>        77 <7,5>        78 <8,6>        79 <9,7>        80 <0,8>
81 <1,9>        82 <2,10>       83 <3,11>       84 <4,0>        85 <5,1>        86 <6,2>        87 <7,3>        88 <8,4>        89 <9,5>        90 <0,6>
91 <1,7>        92 <2,8>        93 <3,9>        94 <4,10>       95 <5,11>       96 <6,0>        97 <7,1>        98 <8,2>        99 <9,3>        100 <0,4>
101 <1,5>       102 <2,6>       103 <3,7>       104 <4,8>       105 <5,9>       106 <6,10>      107 <7,11>      108 <8,0>       109 <9,1>       110 <0,2>
111 <1,3>       112 <2,4>       113 <3,5>       114 <4,6>       115 <5,7>       116 <6,8>       117 <7,9>       118 <8,10>      119 <9,11>
"""
