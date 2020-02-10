## C/C++/STL ���� to Python

## ����!

1. input() ���� sys.stdin.readline() �� �������.

2. ����Լ��� �ִ� ���, �ִ� ��� ���̸� ��������� �Ѵ�.

```
import sys sys.setrecursionlimit(10**8) # 10^8 ���� �ø�.

```

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

# 2,8,16 ���� ���� �� ���

print(0b101)  # �������� 5

print(0o10)  # �������� 8

print(0xF)  # �������� 15

# ��� ���� ���� ���ϱ�
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

# ����Ʈ���� ������ �޴µ� ����� �𸦰��

a, *b = [1, 2, 3, 4, 5, 6]
print(a)
print(b)

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

## ���ٽ� | map ( �����Ҹ� 2�� ���Ҽ��ִ�. ) | filter (�迭���� ¦���ΰ�츸 ơ)

```python

# ���ٽ� | map ( �����Ҹ� 2�� ���Ҽ��ִ�. ) | filter (�迭���� ¦���ΰ�츸 ơ)
# (x,y) => x+y
# lamda x,y: x+y


def g(x): return x**2


(a, b, c) = map(g, [1, 2, 3])  # ���� ���� �� ���� 2����
print(a, b, c)


(a, b, c) = map(lambda x: x*2, [1, 2, 3])  # ���ٷ�, �� ���� 2��
print(a, b, c)

res = list(map(lambda x: x*2, [1, 2, 3]))  # ���ٷ�, �� ���� 2��
print(res)

wannaEven = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
res = list(filter(lambda e: e % 2 == 0, wannaEven))  # filter������Ʈ���� list�� ��ȯ�ϱ�.
print(res)

```

# bool �� ��

```python
if(True and False or not True):
    while(True):
        if(bool('False')):  # ��� ���ڿ��� ����!!!
            break
```

# ����Ʈ ����� (range ��ü ����ϱ�.)

```python
a = [] # Ȥ�� a = list()
b = list(range(10)) # 0���� 9���� range ��ü ����� list�� ��ȯ
print(b)

c = list(range(1, 5)) # [1, 2, 3, 4]
print(c)

c = list(range(1, 11, 2)) # [1, 3, 5, 7, 9] # 1���� 10���� 2������ | 11���� �ȵ�
print(c)

c = list(range(10, 0, -1)) # [10, 9, 8, 7, 6, 5, 4, 3, 2, 1] �� ���� 0�� �� ����.
print(c)

# for������ ���ڿ� ����Ʈ -> ���� ����Ʈ ��ȯ �� ��

nlist = [int(x) for x in ['10', '20', '30']]
print(sum(nlist))

```

# enumerate()

```python
var = ['a', 'b', 'c']

for i, val in enumerate(var):
print(i, val)
```

# 2���� �迭

```python
a = [[10, 20], [30, 40], [50, 60]]

for x, y in a:  # ����Ʈ ��ü�� �޾Ƽ� ���
    print(x, y)

for i in a:  # ����Ʈ�� ���Ҹ� 2������ ���
    for j in i:
        print(j, end=' ')

for i in range(len(a)):  # ���̸�ŭ ���
    for j in range(len(a[i])):
        print(a[i][j])

for i, x in enumerate(a):
    for j, y in enumerate(x):
        print(a[i][j])


for i, x in enumerate(a):
    for j, y in enumerate(x):
        print(y)
```

# �ݺ������� 2���� | �迭 �����

```python
a = ['x' for i in range(3)]
print(a) # ['x', 'x', 'x']

a = [[0, 0, 0] for i in range(3)]
print(a) # [[0, 0, 0], [0, 0, 0], [0, 0, 0]]

a = [[0 for i in range(3)] for i in range(3)]
print(a) # [[0, 0, 0], [0, 0, 0], [0, 0, 0]]

# for������ ����Ʈ �ϼ��ϱ�

nlist = [int(x) for x in ['10', '20', '30']]
print(sum(nlist))

```

# Ʃ�� ����� ( Ʃ���� �б� ���� ����Ʈ )

```python
c = tuple(range(0, 10)) # range to tuple
print(c) # print (0, 1, 2, 3, 4, 5, 6, 7, 8, 9)
print(list(c)) # tuple to list
```

# ������ Ȱ��.

- ������ �ڷ����̶�: ����Ʈ, Ʃ��, range, string, bytes, bytearray = > �����̽� ��� ����!

## ������ ���缺.

```python
a = [0, 1, 2, 'a', "hello", True, [0, 'dos', True], (0, 'impact', False)]

print(1 in a) # ��
print(10 in a) # ����
print('a' in a) # ��
print(True in a) # ��

print(1 not in a) # ����
print(10 not in a) # ��
print('a' not in a) # ����
print(True not in a) # ����

print('ll' in a[4]) # ��

print('dos' in a[6])  # ��
print('do' in a[6])  # ����
print('do' in a[6][1])  # ��

print('impact' in a[7])  # ��
print('act' in a[7])  # ����
print('act' in a[7][1])  # ��
```

# ������ with => len + ���ϱ� del

```python
a = [1, 2, 3]
b = [4, 5, 6, 7, 8, 9, 10]
st = 'hello'
print(len(st)) # 5
print(a+b) # [1, 2, 3, 4, 5, 6]
print(a*2) # [1, 2, 3, 1, 2, 3]
print(a[-1]) # 3 (�ڿ��� ù��°)

del a[1] # 1��° �ε��� ����
print(a) # [1, 3]
```

# ������ with => slice [][:]

```python
print(b[0:2]) # [4, 5]
print(b[0:]) # [4, 5, 6, 7, 8, 9, 10]
print(b[0:-1]) # [4, 5, 6, 7, 8, 9]
print(b[0:-1:2]) # 2�� �����ϸ鼭 �������� [4, 6, 8]

print(b[::2]) # [4, 6, 8, 10] ¦���� �ε����� ��������.

print(b[::-1]) # �� ���� [10, 9, 8, 7, 6, 5, 4]

print(b[1::] + b[0:1:]) # �����̼� [5, 6, 7, 8, 9, 10, 4]
```

# join �Լ� : ����Ʈ���̻��� Ư�� ���ڿ��� �ְ�, �ϳ��� ���ڿ��� ������ش�. ( splite�� �ݴ��� ����)

```
var = ['A', 'B', 'C']

print(''.join(var))  # ABC
print('|'.join(var))  # A|B|C
```

# sum,min,max,sorted

```python
var = [1, 2, 3, 4, -1, 100]

print(sum(var))  # 109
print(min(var))  # 01
print(max(var))  # 100
print(sorted(var))  # [-1, 1, 2, 3, 4, 100]
print(sorted(var, reverse=True))  # [100, 4, 3, 2, 1, -1]

var = (1, 2, 3, 4, -1, 100)

print(sum(var))  # 109
print(min(var))  # 01
print(max(var))  # 100
print(sorted(var))  # [-1, 1, 2, 3, 4, 100]

var = "EABCD"
# print(sum(var))  #TypeError: unsupported operand type(s) for +: 'int' and 'str'
print(min(var))  # A
print(max(var))  # E
print(sorted(var))  # ['A', 'B', 'C', 'D', 'E']
```

# ����Ʈ append sort reverse index insert remove pop count extend

```python
a = [50, 20, 3, 4, 5]
a.append(6)
print(a)  # [50, 20, 3, 4, 5, 6]

a.extend([7, 8])
print(a)  # [50, 20, 3, 4, 5, 6, 7, 8]

a.sort()
print(a)  # [3, 4, 5, 6, 7, 8, 20, 50]

a.sort(reverse=True)
print(a)  # [50, 20, 8, 7, 6, 5, 4, 3]

a.reverse()
print(a)  # [3, 4, 5, 6, 7, 8, 20, 50]

idx = a.index(20)  # ���� 20�� ��ġ�� 6��°.
print(idx)  # 6

a.insert(idx, 21)  # 20��ġ�� �ϳ� �и���, 21�� ��
print(a)  # [3, 4, 5, 6, 7, 8, 21, 20, 50]

a.remove(21)  # 21 ã�Ƽ� ����
print(a)  # [3, 4, 5, 6, 7, 8, 20, 50]

a.pop()
a.pop()
print(a)  # [3, 4, 5, 6, 7, 8]

print([3, 3, 3, 2, 2, 1].count(3))  # 3
```

# ��ųʸ� ���(obj)

```python

x = {'base': 1, 'dos': 20}
print(x['base'])

# �Ǻ���ġ + dp for�� | dp ���

d = {}


def dp(n):
    if(n <= 1):
        return n
    if((n) in d):
        return d[(n)]
    d[n] = dp(n-1)+dp(n-2)
    return d[n]


var = int(input())
d[0] = 0
d[1] = 1
for i in range(2, var+1):
    d[i] = d[i-1] + d[i-2]
print(dp(var))


```

# python - �� ( ť��� ���� ����. ť�� �������� �ƴϴ�.)

```python
from collections import deque

dq = deque([1, 2, 3, 4])

print(dq[0])  # front
print(dq[-1])  # back
print(len(dq))  # size

dq.append(5)  # push_back
dq.appendleft(6)  # push_front

print(dq.pop())  # pop_back
print(dq.popleft())  # pop_front

dq.rotate()
print(list(dq))
```

# set �Լ� ���� (���缺 ������ ����)

```python
var = [5, 1, 1, 2, 2, 2, 3, 3, 3, 3]

print(set(var))  # ���������� obj�ε� {1, 2, 3, 5}

var = list(set(var))
var.sort()
print(var)  # unique �ߺ����� && ���� [1, 2, 3, 5]
```

# �켱���� ť ����ϱ�. heappush,heappop,heapify

```python
import heapq

# �� ����� push = logn && n�� ���� = n => �� �ð� ���⵵ : nlogn
h = []  # �켱���� ť�� ���� ����Ʈ
heapq.heappush(h, (3, "Go to home"))  # �ι��� ���ڴ� (�켱����,��)
heapq.heappush(h, (10, "Do not study"))
heapq.heappush(h, (1, "Enjoy!"))
heapq.heappush(h, (4, "Eat!"))
heapq.heappush(h, (7, "Pray!"))
print(h)


# �� ������ nlogn
print(heapq.heappop(h))  # �켱���� ������� ���´�. 1 -> 3 -> 4 -> 7 -> 10
print(heapq.heappop(h))
print(heapq.heappop(h))
print(heapq.heappop(h))
print(heapq.heappop(h))

# �� ����� by �̹�  ������� ����Ʈ -> �� ���� : O(n) �ɸ�
hlist = [(7, 'kdy'), (2, 'dos'), (4, 'hello')]

heapq.heapify(hlist)
print(heapq.heappop(hlist))
print(heapq.heappop(hlist))
print(heapq.heappop(hlist))

```

# ���� ���� ���� permutations combinations import itertools

```python
import itertools

pool = ['A', 'B', 'C']

# ����� Ʃ�÷� ��ȯ�ȴ�. -> join�� ���� �ϳ��� ���ڿ��� ��ó�� �� �ִ�.

# [('A', 'B', 'C'), ('A', 'C', 'B'), ('B', 'A', 'C'), ('B', 'C', 'A'), ('C', 'A', 'B'), ('C', 'B', 'A')]
print(list(itertools.permutations(pool)))

#['ABC', 'ACB', 'BAC', 'BCA', 'CAB', 'CBA']
print(list(map(''.join, itertools.permutations(pool))))  # 3���� ���ҷ� ���� �����
#['AB', 'AC', 'BA', 'BC', 'CA', 'CB']
print(list(map(''.join, itertools.permutations(pool, 2))))  # 2���� ���ҷ� ���� �����

# [('A', 'B'), ('A', 'C'), ('B', 'C')]
print(list(itertools.combinations(pool, 2)))
# ['ABC']
print(list(map(''.join, itertools.combinations(pool, 3))))  # 3���� ���ҷ� ���� �����
#['AB', 'AC', 'BC']
print(list(map(''.join, itertools.combinations(pool, 2))))  # 2���� ���ҷ� ���� �����
```

//2.2 ��½� �Ҽ��� ó���ϱ�
#include<iomanip>
setprecision(5)
fixed
eg)
double f = 3.1415926535;
cout<<setprecision(5)<<f; //�տ��� 5��°���� ���(�ݿø�����)

cout<<fixed<<setprecision(5)<<f; //�Ҽ��� �ڸ����� 5��° ���� ���(�ݿø� ����)

//3.13 bitset

//vector<bool> ���� , 1bit�� ����Ѵ�.

bitset<10> b2(88) //10�ڸ� 2������ ����µ�, ������ 88�� ��������
bitset<10> b2("10010")//10�ڸ� 2������ ����µ�, 2���� 10010�� ��������
bitset<n> b2 // �ַ�

    bitset<100000>a;
    bitset<100000>b;

    cin >> a >> b;

    cout << (a & b) << '\n'; //AND
    cout << (a | b) << '\n'; //OR
    cout << (a ^ b) << '\n';	//XOR
    cout << ~(a) << '\n';	//NOT
    cout << ~(b);		//NOT

eg)����

b2[i]
b2.test(i)

b.flip() b.flip(1) // 0 => 1, 1 => 0
b.set() b.set(1) // 0,1 => 1��
b.reset() b.reset(1) //0,1 => 0����

b.all() //��� 1?
b.any() //��� �Ѱ��� 1?
b.none() //��� 0?
b.count()//1�� ��ΰ�?

//���� ���� �ð� --> ���ʹ� N , set�� lgN, ����Ʈ�� 1
//count�� �ǹ� set������ ���缺 / multiset ������ ���� / STL�� count�� ����, map,unordered_map���� ���缺

Sec5. STL - Algorithm

//#5.9 ���� Ž��, ���� Ŀ���� ���� ����� ��찡 ���ѵ�,
binary_search(begin,end,value); //true or false
binary_search(begin,end,value,cmp); // true or false

---

//#5.12 ����

next_permutation(v.begin(),v.end()); //���� ����
prev_permutation(v.begin(),v.end()); //���� ����
