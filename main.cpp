#include <cstdio>
#include <iostream>
#include <tuple>
#include <queue>
#include <algorithm>
#include <deque>
#include <vector>
#include <string>
#include <stack>
#define SIZE 101

using namespace std;
int n, m;
int graph[SIZE][SIZE];
int check[SIZE][SIZE][2]; //0 �湮 x | 1�̻���� �湮�� + �Ÿ���
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
bool noans = true;

void bfs(int x, int y, int c)
{
    check[x][y][c] = 1;
    deque<tuple<int, int, int>> dq;
    dq.push_back({x, y, c});
    while (!dq.empty())
    {
        tie(x, y, c) = dq.front();
        dq.pop_front();
        if (x == n - 1 && y == m - 1)
        {
            printf("%d", check[x][y][c]);
            noans = false;
            return;
        }
        for (int k = 0; k < 4; k++) // �ֺ� ��带 Ž��
        {

            int nx = x + dx[k], ny = y + dy[k];
            //���� üũ -> ���� ���� �ȺνŰ�� -> �׳��̵� �Ǵ� �νð� �̵� | �νŰ��
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (c == 0)
            { //���� üũ -> ���� ���� �ȺνŰ�� -> ���� �ƴѰ��
                if (graph[nx][ny] == 0 && check[nx][ny][c] == 0)
                {
                    check[nx][ny][c] = check[x][y][c] + 1;
                    dq.push_back({nx, ny, c});
                }
                else if (graph[nx][ny] == 1 && check[nx][ny][c] == 0)
                {
                    check[nx][ny][c + 1] = check[x][y][c] + 1;
                    dq.push_back({nx, ny, c + 1});
                }
            }
            else if (c == 1)
            {
                if (graph[nx][ny] == 0 && check[nx][ny][c] == 0)
                {
                    check[nx][ny][c] = check[x][y][c] + 1;
                    dq.push_back({nx, ny, c});
                }
            }
        }
    }
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%1d", &graph[i][j]);
        }
    }
    bfs(0, 0, 0);
    if (noans)
    {
        printf("%d", -1);
    }
}
