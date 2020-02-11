# Section1. ���� ���� �Է� ���

## ���� | Ÿ�� | �⺻���� | ����

```python

#  �⺻ ������
print(7/3)  # �Ҽ��� ì��� ������
print(7//3)  # �Ҽ��� ������ ������
print(7 % 3)  # mod
print(2 ** 3)  # pow

# �� �� ������
print(divmod(7, 3))  # Ʃ�÷� (2,1) ��ȯ.

# �� ��� �� �� ��ȯ
print(type(3.3))  # float �� ���
print(int(3.3))  # �Ҽ��� ������ | int��
print(int('10'))  # string to int
print(str(10)) # int to str



```

# �ƽ�Ű�ڵ� (int) -> chr ��ȯ �� �� ��ȯ ord

```python
data = 97

data = chr(data)
print(data) # a
print(type(data)) # <class 'str'>

data = ord(data)
print(data) # 97
print(type(data)) # <class 'int'>
```

# bool �� ��

```python
if(True and False or not True):
    while(True):
        if(bool('False')):  # ��� ���ڿ��� ����!!!
            break
```

# ��Ʈ ������ �� ���� ��ȯ

```python
# 1. int 10������ ���� -> ��Ʈ ������ ���� ( ���⿡�� 10�������� ���������δ� bit���� �� �ǰ� ����)
# 2. int 10������ -> str ������ 2����,8����,16���� �� ��� ����
# 3. str���¸� �ڽ� int 10������ ��ȯ ����


# 1. int 10������ ���� -> ��Ʈ ������ ���� ( ���⿡�� 10�������� ���������δ� bit���� �� �ǰ� ����)

var = 1
print(var << 1)  # 2
print(var << 2)  # 4
print(var << 3)  # 8
print(7 | 5)  # 7

# 2. ������ int -> str : ������, ������, 16���� ��ȯ �� ���


var = bin(7)
print(type(var))  # <class 'str'>
print(var)  # 0b111

var = hex(15)
print(type(var))  # <class 'str'>
print(var)  # 0xf

var = oct(8)
print(type(var))  # <class 'str'>
print(var)  # 0o10

# 3. str : ������, ������, 16����  -> int ������  ��ȯ �� ���

var = '0b111'
print(int(var, 2))  # 7

var = '0xf'
print(int(var, 16))  # 15

var = '0o10'
print(int(var, 8))  # 8

# 4. ������ ���� : ������, ������, 16����  -> int ������  ��ȯ �� ���

print(0b101)  # �������� 5

print(0o10)  # �������� 8

print(0xF)  # �������� 15

# ���� ) ��� ���� ���� ���ϱ� ( 2����,8����,16����  ���ڿ��� -> 10������ ���)
# https://www.acmicpc.net/problem/11816

a = input()
if(a[0] == '0'):
    if(a[0:2] == '0x'):
        print(int(a[2:], 16))
    else:
        print(int(a[1:], 8))

else:
    print(int(a))

```

# ������ ������ ���� => ����� �������ε�, ������ -1�� ����Ű�� �迭�� ������ �迭���� �ȴٸ� ���ž���.

```python
"""
0 1 2 3 4 <- �迭 ���� : 5

0 1 2 3 4
5 6 7 8 ...

-5 -4 -3 -2 -1
.. -9 -8 -7 -6

"""

var = [0, 1, 2, 3, 4]

print(len(var)) # ���� 5

print(0 % len(var)) # 0 ~ 4
print(1 % len(var))
print(2 % len(var))
print(3 % len(var))
print(4 % len(var))

print(5 % len(var)) # 0 ~ 4
print(6 % len(var))
print(7 % len(var))
print(8 % len(var))
print(9 % len(var))

print(-1 % len(var)) # 4 ~ 0
print(-2 % len(var))
print(-3 % len(var))
print(-4 % len(var))
print(-5 % len(var))

print(-6 % len(var)) # 4 ~ 0
print(-7 % len(var))
print(-8 % len(var))
print(-9 % len(var))
print(-10 % len(var))
```

## ���� (����)

```python
# variable & type

a, b, c = 10, '20', 30

print(a, b, c)
print(type(a), type(b), type(c))

# Swap

a, c = c, a
print(a, b, c)

# variable => None | del ( �� , None �� not defined�� �ٸ���.!!)

var1 = 10
del var1
# print(var1) # NameError: name 'var1' is not defined
var1 = None
print(var1)  # None

```

## ���� (�Է�,���)

```python
# input

var1 = input()  # input : 10 | str ������ �Էµ�
print(type(var1))

var1 = int(input())  # input : 10 | int�� �� ��ȯ
print(type(var1))


# input ������ �޾Ƽ�, �������� �����ϱ� ������ str�� ��

u, v = input().split()
print(u, v)
print(type(u), type(v))

# input �ٷ� int������ �޴� ���.

u, v = map(int, input().split())
print(u, v)
print(type(u), type(v))


# print ����  \n �� �ֱ�

a, b, c = map(int, input().split(','))  # input 10,20,30
print(a, b, c, sep='\n')  # output 10\n20\n30

print(a, end='')  # output 102030
print(b, end='')
print(c, end='\n')

print(a, end=' ')  # output 10 20 30
print(b, end=' ')
print(c, end='')


```

# python - �⺻ �Է��� �̰ɷ� ~ ���� �Է��ϱ�.

# def input(): return sys.stdin.readline().rstrip()

```python

# ���� ���� �б� | ���� ���� ����ϴµ� : rstrip()  # �ش� ���ڿ��� ���� �� ���� ����
import sys

var = ' hi \n'
print(len(var))  # 5

var = var.rstrip()  # �ش� ���ڿ��� ���� �� ���� ����
print(len(var))  # 3

var = var.strip()  #
print(len(var))  # 2
# ����Ʈ���� ������ �޴µ� ����� �𸦰��

a, *b = [1, 2, 3, 4, 5, 6]
print(a)  # �׳� int 1
print(b)  # ����Ʈ ���� [2, 3, 4, 5, 6]


# print �ȿ� if�� ���

print('������' if False else '����')  # ����

# [] �ȿ� if�� ���

var = ['������' if True else 'nonono']
print(var)  # ['������']

# ���� ���پ� �б�
# https://www.acmicpc.net/problem/10866
from collections import deque
import sys


def input(): return sys.stdin.readline().rstrip()


dq = deque()
t = int(input())

for _ in range(t):
    a, *b = input().split()
    if(a == 'push_front'):
        dq.appendleft(b[0])
    elif(a == 'push_back'):
        dq.append(b[0])
    elif(a == 'pop_front'):
        print(dq.popleft() if len(dq) != 0 else -1)
    elif(a == 'pop_back'):
        print(dq.pop() if len(dq) != 0 else -1)
    elif(a == 'size'):
        print(len(dq))
    elif(a == 'empty'):
        print(0 if len(dq) != 0 else 1)
    elif(a == 'front'):
        print(dq[0] if len(dq) != 0 else -1)
    elif(a == 'back'):
        print(dq[-1] if len(dq) != 0 else -1)


```

# python - �Է� ����, EOF ���� | ���� �׳� | spilt �̿��ؼ�

```python
# ���ڿ� ������ �׳� �ޱ�
a = input()
print(a)

# ������ ������ �˸;��� �ޱ� -> ����Ʈ�� ��ȯ��
a = input().split()
print(a)

# EOF(ctrl+Z) ���� ���� ���� �Է¹ޱ� (���� ���� �ϴ� ����)

# https://www.acmicpc.net/problem/11718
import sys

for line in sys.stdin:
    a = line
    print(a, end='')  # line��ü�� enter�� ������ �ִ�.

# EOF(ctrl+Z) �ѹ��� �Է¹ޱ� (���� ���� �ϴ� ����)

# https://www.acmicpc.net/problem/11718
import sys
v = sys.stdin.read()
print(v, end='')

# EOF(ctrl+Z) ���� ���� ���� �Է¹ޱ� (���� ���� �˸��� ���ڿ���)

import sys

for line in sys.stdin:
    a = line.split()
    print(a)

# EOF(ctrl+Z) ���� ���� a,b  �Է¹ޱ�

import sys

for line in sys.stdin:
    a, b = map(int, line.split())
    print(a + b)

# EOF ���� �ѹ��� �о, �پ��� �����ϰ� ,�� ������ ����Ʈ�� ��ȯ�� ���Ѱ��� ����ϱ�
# https://www.acmicpc.net/problem/10823
import sys

nlist = [int(x) for x in sys.stdin.read().replace('\n', '').split(',')]
print(sum(nlist))

#  ���� ���� ���ڿ� �ϳ��ϳ� �и��ϱ�

a = input()
print(list(a))

#  ���� ���� �� ���ڿ� �ϳ��ϳ� �и��ϱ�

a = input().split()
for e in a:
    print(list(e))

#  1234 ���� �Է½� , 1,2,3,4 �� �ϳ��� ���� �ޱ� ( ���� ó�� �Ұ���  )

a = list(input())
res = list(map(int, a))

print(res)

#  1234 ���� �Է½� , 1,2,3,4 �� �ϳ��� ���� �ޱ� ( ���� ó�� ���� )
ans = []
a = input().split()
for e in a:
    res = list(map(int, e))
    ans.extend(res)

print(ans)



# �پ�� ó���ϱ� -> replace('\n','')

import sys

var = sys.stdin.read()
var = (var.replace('\n', '').split(','))
print(sum(list(map(int, var))))


```
