"""

조사한 n분
터널안 차량의 수 m

0 - 1 : 2 3  1
1 - 2 : 2 3  0
2 - 3 : 4 1  3
"""


import sys


def input(): return sys.stdin.readline().rstrip()


n = int(input())
now = int(input())
maxVal = -1
for _ in range(n):
    i, o = map(int, input().split())
    now += i
    now -= o
    if now < 0:
        print(0)
        exit(0)
    maxVal = max(now, maxVal)
print(maxVal)
