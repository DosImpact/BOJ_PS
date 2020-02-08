//https://www.acmicpc.net/problem/10942
#include <iostream>
#include <tuple>
#include <queue>
#include <algorithm>
#include <deque>
#include <vector>
#include <string>
#include <stack>
#include <string>
#define SIZE 2001
using namespace std;

int s[SIZE];
int n;
int d[SIZE][SIZE];
int dp(int i, int j)
{ //���ڿ� i���� j���� �縰����̳� | ���� 1 : true | ���� 2 : ��� ������ true | ���� 3 �̻��� ��� : dp[i-1][j-1]�� ���̰�, s[i]==s[j] ��� �縰���
    if (i == j)
    {
        return 1;
    }
    else if (i + 1 == j)
    {
        return s[i] == s[j];
    }

    if (d[i][j] >= 0)
    {
        return d[i][j];
    }
    if (s[i] != s[j])
    {
        return d[i][j] = 0;
    }
    else
    {
        return d[i][j] = dp(i + 1, j - 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fill(&d[0][0], &d[0][0] + SIZE * SIZE, -1);
    int t;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    cin >> t;
    while (t--)
    {
        int s, e;
        cin >> s >> e;
        cout << dp(s, e) << " \n";
    }
}