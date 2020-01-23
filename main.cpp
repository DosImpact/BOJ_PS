//https : //www.acmicpc.net/problem/14226
#include <iostream>
#include <tuple>
#include <queue>
#include <algorithm>
#define SIZE 1001
using namespace std;
int d[1001][1001];

int main()
{
    //���� �̸�Ƽ�� �� n
    int n;
    cin >> n;
    fill(&d[0][0], &d[0][0] + SIZE * SIZE, -1);
    queue<pair<int, int>> q;
    q.push({1, 0});
    d[1][0] = 0; // -1 �̸� �湮 ����.
    //d��带 d[n][0~n] ������ BFS
    while (!q.empty())
    {
        //ť���� ���� ��带 ����
        int s, c;
        tie(s, c) = q.front();
        q.pop();
        if (s == n)
        {
            cout << d[s][c];
            return 0;
        }
        // s,c => s,s | ���� üũ �� �湮���� üũ
        if (d[s][s] == -1)
        {
            d[s][s] = d[s][c] + 1;
            q.push({s, s});
        }
        // s,c => s+c, c
        if (s + c <= n && d[s + c][c] == -1)
        {
            d[s + c][c] = d[s][c] + 1;
            q.push({s + c, c});
        }
        // s,c => s-1, c
        if (s - 1 > 0 && d[s - 1][c] == -1)
        {
            d[s - 1][c] = d[s][c] + 1;
            q.push({s - 1, c});
        }
    }
}