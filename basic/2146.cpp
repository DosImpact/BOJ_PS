//https://www.acmicpc.net/problem/2146

#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int a[100][100]; //���� ����
int g[100][100]; //�׷�
int d[100][100]; //�Ÿ�
int main()
{
    //���� �Է¹ޱ�
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int ele;
            scanf("%d", &ele);
            a[i][j] = ele;
        }
    }

    //���� �׷쳪����
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 1 && g[i][j] == 0)
            {
                queue<pair<int, int>> q;
                g[i][j] = ++cnt;
                q.push(make_pair(i, j));
                while (!q.empty())
                {
                    auto current = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = current.first + dx[k];
                        int ny = current.second + dy[k];
                        if (nx >= 0 && ny >= 0 && nx < n && ny < n)
                        {
                            if (a[nx][ny] == 1 && g[nx][ny] == 0)
                            {
                                g[nx][ny] = g[current.first][current.second];
                                q.push(make_pair(nx, ny));
                            }
                        }
                    }
                }
            }
        }
    }

    //**�Ÿ� �ٸ��ֱ� , -1, �Ǵ� 0���� ���ÿ� queue�� �ֱ�.

    //������ ���鼭
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            d[i][j] = -1;
            if (g[i][j] != 0)
            {
                //g�� ������ 0���� ������ -1�� �ٸ��ش�.
                //g�� �ִ� ��쿡�� d�� ť�� �־��ش�.
                d[i][j] = 0;
                q.push(make_pair(i, j));
            }
        }
    } //g�� ����ִ� ť�� ���鼭
    while (!q.empty())
    {
        auto current = q.front();
        q.pop();
        // g�� �ֺ��� Ž���ϸ�
        for (int k = 0; k < 4; k++)
        {
            int nx = current.first + dx[k];
            int ny = current.second + dy[k];
            //���� | d�� -1���� | check
            if (nx >= 0 && ny >= 0 && nx < n && ny < n)
            {
                if (d[nx][ny] == -1)
                { // g�� ���� / d�� += 1 �� ���ָ鼭 q�� �ٽ� �־��ش�.
                    d[nx][ny] = d[current.first][current.second] + 1;
                    g[nx][ny] = g[current.first][current.second];
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    // printf("\n");
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         printf("%d ", a[i][j]);
    //     }
    //     printf("\n");
    // }

    // printf("\n");
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         printf("%d ", g[i][j]);
    //     }
    //     printf("\n");
    // }

    // printf("\n");
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         printf("%d ", d[i][j]);
    //     }
    //     printf("\n");
    // }
    //���� �����ϱ�.
    int ans = -1;
    //��ü ������ ���鼭
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n)
                {
                    if (g[i][j] != g[nx][ny])
                    { //�ֺ� ���� �׷��� �ٸ��� // �Ÿ��� �ջ��ؼ�

                        // ans�� �ּҰ��� �ִ´�.
                        int tmp = d[i][j] + d[nx][ny];
                        if (ans == -1 || ans > tmp)
                        {
                            ans = tmp;
                        }
                    }
                }
            }
        }
    }
    printf("%d", ans);
}