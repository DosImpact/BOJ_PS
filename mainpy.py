
import sys


def input(): return sys.stdin.readline().rstrip()


a = list(map(int, input()))
b = list(map(int, input()))
tmp = [0]*len(a)


def sol(func):
    for i in range(len(a)):
        tmp[i] = func(a[i], b[i]) % 2
    print(''.join(map(str, tmp)))


sol(lambda x, y: x & y)
sol(lambda x, y: x | y)
sol(lambda x, y: x ^ y)
sol(lambda x, y: ~x)
sol(lambda x, y: ~y)
