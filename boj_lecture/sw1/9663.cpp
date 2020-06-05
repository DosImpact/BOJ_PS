//https://www.acmicpc.net/problem/9663

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int n; //15����,
bool queuen[16][16];
int ans = 0;
//���� row
bool check(int x, int y)
{
    //���� �˻�.
    bool isOk = true;
    int nx = x - 1;
    for (int i = 0; i <= nx; i++)
    {
        if (queuen[i][y])
        {
            isOk = false;
        }
    }
    //���� �˻�.fb ) �ݵ�� ������ �ۿ� ...
    int ny = y - 1;
    for (int i = 0; i <= ny; i++)
    {
        if (queuen[x][i])
        {
            isOk = false;
        }
    }
    //���� �밢�� �˻�.
    nx = x - 1;
    ny = y - 1;
    while (nx >= 0 && ny >= 0)
    {
        if (queuen[nx][ny])
        {
            isOk = false;
        }
        nx--;
        ny--;
    }
    //���� �밢�� �˻�.
    nx = x - 1;
    ny = y + 1;
    while (nx >= 0 && ny < n)
    {
        if (queuen[nx][ny])
        {
            isOk = false;
        }
        nx--;
        ny++;
    }
    return isOk;
}
void go(int row)
{
    //row�� �� ä������, �ϼ���!
    if (row == n)
    {
        ans++;
        return;
    }
    //���� row���� �÷��� ���鼭, �ѹ� ��ġ�� ���� ����
    for (int i = 0; i < n; i++)
    {
        //cout << check(row, i) << " ";
        if (check(row, i))
        {
            //�������� ���� row�� �Ѿ��.
            queuen[row][i] = true;
            go(row + 1);
            queuen[row][i] = false;
        }
    }
}
int main()
{
    cin >> n;
    go(0);
    cout << ans << "\n";
}