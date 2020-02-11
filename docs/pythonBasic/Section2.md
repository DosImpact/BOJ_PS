# Section2. ������ ������ �ڷ� ����

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
