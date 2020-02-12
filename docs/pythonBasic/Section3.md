# Section3. ������ ������ �˰���

# sum,min,max,sorted | ��,�ּ�,�ִ�,����

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

# ���̽� �����ϱ� | Ŀ���� ����

```python
# data.sort() ���� ������, None��ȯ -> ������ �Ѽյȴ�.

# sorted(����Ʈ,reverse,key) �� ���� �Ѽ� ���� ��� ����


data = ['su', 'bed', 'app', 'king']

res = sorted(data)
print(res)  # ['bed', 'king', 'su']

res = sorted(data, reverse=True)
print(res)  # ['su', 'king', 'bed']

res = sorted(data, key=lambda x: len(x))  # ���̰� ������
print(res)  # ['su', 'bed', 'app', 'king']

res = sorted(data, key=lambda x: (len(x), x))  # ���̰� ������ + ������
print(res)  # ['su', 'app', 'bed', 'king']

res = sorted(data, key=lambda x: (len(x), x), reverse=True)  # ���̰� ������ + ������
print(res)  # ['king', 'bed', 'app', 'su']
```

# ����Ʈ append sort reverse index insert remove pop count extend | push,pop | ����, ��ġ, ����,

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

# python - �� ( ť��� ���� ����. ť�� �������� �ƴϴ�.) | �����̼ǵ� �߰��Ǿ� ����.

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

# python - bitset

```python

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

```
