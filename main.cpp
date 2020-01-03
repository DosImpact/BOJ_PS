//https://www.acmicpc.net/problem/15657

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int c[10];
int a[10];
int num[10];
int n, m;
void printArray()
{
    for (int i = 0; i < m; ++i)
    {
        cout << num[a[i]] << " ";
    }
    cout << "\n";
}
//a curosr
void go(int ac, int start)
{
    //다고른경우
    if (ac == m)
    {
        printArray();
        return;
    }
    for (int i = start; i < n; i++)
    {
        a[ac] = i;
        go(ac + 1, i);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        num[i] = tmp;
    }
    sort(num, num + n);
    go(0, 0);
}