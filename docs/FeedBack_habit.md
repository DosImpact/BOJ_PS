# ���� Ǫ�� �µ��� ������ �����մϴ�.

### BFS ����� ������ Ǯ�鼭, �������� �� �Ӹ������� �����ϰ� �ڵ带 ���� �ϴµ��� �Ѱ谡 �ִ�.

- ???? �ִ��� ���� �ּ����� ���� ����ΰ�, �ڵ�� �ϳ��ϳ� �����ϴ� ����� ������ ����.!!! ????

### ��Ʈ��ŷ �ϸ鼭 �����ǵ�, 1���� Ǫ�°ű� ������, �׳� �������� �����ص� ��� ����.!!

- ���� ����Լ��� �ĸ����� �ø��� ����, ���������� ����� ����.

```cpp
void go(int sum, int index)
{
    //�ε��� ����
    if (index == n)
    {
        if (sum == s)
        {
            ans++;
        }
        return;
    }
    go(sum + a[index], index + 1);
    go(sum, index + 1);
}
```

```cpp
int go(vector<int> &number, vector<int> current, int nextNumber)
{
    int row = 0;
    //fb)��� ���ϴٰ� 0�� �Ǵ� ��쵵 �־�.
    //������ ���� ����غ��� ������ 1�� ��ȯ
    if (isSumS(current) && number.size() == nextNumber)
    {
        return 1;
    }
    //�� ���� ������ 0 ��ȯ
    if (!isSumS(current) && number.size() == nextNumber)
    {
        return 0;
    }
    //���.
    current.push_back(number[nextNumber]);
    row += go(number, current, nextNumber + 1);
    current.pop_back();
    row += go(number, current, nextNumber + 1);

    return row;
}
```
