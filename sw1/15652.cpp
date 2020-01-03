//https://www.acmicpc.net/problem/15652

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[10];
int n, m;
void printArray()
{
    for (int i = 0; i < m; ++i)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}
//a Ŀ�� , �� ����.
void go(int ac, int start)
{
    //���̽�)�� �����
    if (ac == m)
    {
        printArray();
        return;
    }

    //���) fb)���� ��� ���ڿ�����, �����ġ��, �������ڵ� ���� �غ���.
    for (int i = start; i <= n; i++)
    {
        a[ac] = i;
        go(ac + 1, i);
    }
}
using namespace std;
int main()
{
    cin >> n >> m;
    go(0, 1);
}