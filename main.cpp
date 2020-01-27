//https://www.acmicpc.net/problem/2206 �����丵
#include <cstdio>
#include <tuple>
#include <queue>
#include <algorithm>
#include <deque>
#define SIZE 101
using namespace std;
int check[SIZE][SIZE]; //[][][2] -> 0 ���Ⱥ� bfs | 1 ���� bfs
int graph[SIZE][SIZE]; //�׷���, ��尡 �и��Ǵ� ��� - check�迭�� 2�������� �д�.
int n, m;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int main()
{
    //�׷��� �Է�
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%1d", &graph[i][j]);
        }
    }
    fill(&check[0][0], &check[0][0] + SIZE * SIZE, -1);
    //0,0���� Ž���� �����Ѵ�.
    deque<pair<int, int>> dq;
    dq.push_back({0, 0});
    check[0][0] = 0;
    while (!dq.empty())
    { //���� ��忡�� Ž�� | ���� üũ | �湮 ���� üũ
        int x, y;
        tie(x, y) = dq.front();
        dq.pop_front();
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (check[nx][ny] != -1)
                continue;
            if (graph[nx][ny] == 0) // grpah�� 0�ΰ�� | push_front �ϰ� , + 0 ����ġ
            {
                check[nx][ny] = check[x][y];
                dq.push_front({nx, ny});
            }
            else if (graph[nx][ny] == 1) //graph �� 1�ΰ�� | push_back �ϰ� , + 1 ����ġ
            {
                check[nx][ny] = check[x][y] + 1;
                dq.push_back({nx, ny});
            }
        }
    }
    printf("%d", check[n - 1][m - 1]);
}