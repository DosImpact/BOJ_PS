//https://www.acmicpc.net/problem/2206
#include <cstdio>
#include <tuple>
#include <queue>
#include <algorithm>
#include <deque>
#define SIZE 1001
using namespace std;
int d[SIZE][SIZE][2];  // -1 �ʱⰪ
int graph[SIZE][SIZE]; // �Է�
int X, Y;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int main()
{
    scanf("%d %d", &X, &Y);
    for (int i = 1; i <= X; i++)
    {
        for (int j = 1; j <= Y; j++)
        {
            scanf("%1d", &graph[i][j]);
        }
    }

    queue<tuple<int, int, int>> q;
    q.push({1, 1, 0});
    d[1][1][0] = 1;
    while (!q.empty())
    {
        //���� ��� ����
        int x, y, z;
        tie(x, y, z) = q.front();
        q.pop();
        // �ֺ� ��带 Ž���ϸ鼭 | ���� üũ |
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx <= 0 || ny <= 0 || nx > X || ny > Y)
                continue;
            //���� ��忡�� z�� 0 �̸� -> 0,1
            if (z == 0)
            {
                if (graph[nx][ny] == 0 && d[nx][ny][0] == 0)
                { //�׳� ���� ��� :  ���� ����| �湮���� üũ |  üũ�ϰ� ť�� �ֱ�
                    d[nx][ny][z] = d[x][y][z] + 1;
                    q.push({nx, ny, z});
                }
                else if (graph[nx][ny] == 1 && d[nx][ny][z + 1] == 0)
                { //���� �νô� ���: ���� �־�| �湮 ���� üũ
                    d[nx][ny][z + 1] = d[x][y][z] + 1;
                    q.push({nx, ny, z + 1});
                }
            }
            else if (z == 1)
            {
                //�׳� ���� ���
                if (graph[nx][ny] == 0 && d[nx][ny][z] == 0)
                { //�׳� ���� ��� :  ���� ����| �湮���� üũ |  üũ�ϰ� ť�� �ֱ�
                    d[nx][ny][z] = d[x][y][z] + 1;
                    q.push({nx, ny, z});
                }
            }
        }
        // for (int i = 1; i <= X; i++)
        // {
        //     for (int j = 1; j <= Y; j++)
        //     {
        //         printf(" %d ", d[i][j][0]);
        //     }
        //     printf("\n");
        // }
    }
    int ans1 = d[X][Y][0];
    int ans2 = d[X][Y][1];
    if (ans1 && ans2)
    {
        printf("%d", min(ans1, ans2));
    }
    else if (ans1)
    {
        printf("%d", ans1);
    }
    else if (ans2)
    {
        printf("%d", ans2);
    }
    else if (!ans1 && !ans2)
    {
        printf("%d", -1);
    }
}