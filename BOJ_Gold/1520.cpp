//https://www.acmicpc.net/problem/1520
#include <iostream>
#include <tuple>
#include <queue>
#include <algorithm>
#include <deque>
#include <vector>
#include <string>
#include <stack>
#include <string>
#define SIZE 501
using namespace std;

int n, m;
int graph[SIZE][SIZE];
int d[SIZE][SIZE]; //�ʱⰪ -1 , 0~ ����

int dp(int i, int j)
{
    if (i == 0 && j == 0)
    {
        return 1;
    }
    if (d[i][j] >= 0) //�޸� �ִ°��
    {
        return d[i][j];
    }
    else
    { //�޸� ���ٸ�
        d[i][j] = 0;
        if (i - 1 >= 0 && graph[i][j] < graph[i - 1][j])
        {
            d[i][j] += dp(i - 1, j);
        }
        if (j - 1 >= 0 && graph[i][j] < graph[i][j - 1])
        {
            d[i][j] += dp(i, j - 1);
        }
        //fb) ��� 4���⿡�� �����ü� �־�, ���̸� �������ٸ��
        if (i + 1 < n && graph[i][j] < graph[i + 1][j])
        {
            d[i][j] += dp(i + 1, j);
        }
        if (j + 1 < m && graph[i][j] < graph[i][j + 1])
        {
            d[i][j] += dp(i, j + 1);
        }
        return d[i][j];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
        }
    }
    fill(&d[0][0], &d[0][0] + SIZE * SIZE, -1);
    cout << dp(n - 1, m - 1);
}