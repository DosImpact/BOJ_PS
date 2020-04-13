"""
# 자주쓰는 알고리즘

-트라이 자료구조 구현하기✅
-행렬 회전하기 시계방향 90됴 ( 노말버전, 파이썬 버전 )✅
-다음 순열 구현하기 ✅
-비트마스크로 모든 집합 순회하기 (1182 BOJ) ✅

"""

import sys

Debug = False


def input(): return sys.stdin.readline().rstrip()


a, b = input().split()

res = list(set(a) & set(b))
idxList = [a.index(r) for r in res]


idxa = min(idxList)
dchar = a[idxa]
idxb = b.index(dchar)
if Debug:
    print(f"didx {idxa} dcahr {dchar} idxb { idxb}")

for i in range(len(b)):
    for j in range(len(a)):
        if i == idxb:
            print(a[j], end="")
        elif j == idxa:
            print(b[i], end="")
        else:
            print(".", end="")
    print()
