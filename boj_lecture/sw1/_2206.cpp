//https://www.acmicpc.net/problem/2206
#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int n, m;
int graph[1001][1001];
int check[1001][1001];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
void printGraph()
{
    printf("\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            printf("%d", graph[i][j]);
        }
        printf("\n");
    }
}
void printCheck()
{
    printf("\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            printf("%d ", check[i][j]);
        }
        printf("\n");
    }
}
struct node
{
    int x;
    int y;
    int state;
};
//���� �ѽð� ����, �ƴ� ����, check�� ���� �����ϴ� �༮�� �¸�.. �ٵ�, ���ѽô°� �Ƴ��ٰ� �������� ����ϴ°��� �������°�찡 ������ ������ �Ƴ�.
void bfs()
{
    queue<node> q;
    q.push({1, 1, 0});
    check[1][1] = 1;
    while (!q.empty())
    {
        //ť���� �ϳ��� ����, �ֺ� ��带 ���ɴ�.
        auto current = q.front();
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int nx = current.x + dx[k];
            int ny = current.y + dy[k];
            //������ üũ�ϰ�, �湮���� �ʾҴٸ�
            if (nx >= 1 && ny >= 1 && nx <= n && ny <= m)
            {
                if (check[nx][ny] == 0)
                {
                    if (graph[nx][ny] == 0)
                    {
                        check[nx][ny] = check[current.x][current.y] + 1;
                        q.push({nx, ny, 0});
                    }
                }
            }
        }
    }
}
void bfs2()
{
    queue<node> q;
    q.push({1, 1, 0});
    check[1][1] = 1;
    while (!q.empty())
    {
        //ť���� �ϳ��� ����, �ֺ� ��带 ���ɴ�.
        auto current = q.front();
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int nx = current.x + dx[k];
            int ny = current.y + dy[k];
            //������ üũ�ϰ�, �湮���� �ʾҴٸ�
            if (nx >= 1 && ny >= 1 && nx <= n && ny <= m)
            {
                if (check[nx][ny] == 0)
                {
                    if (current.state == 0)
                    {
                        if (graph[nx][ny] == 0)
                        {
                            check[nx][ny] = check[current.x][current.y] + 1;
                            q.push({nx, ny, 0});
                        }
                        if (graph[nx][ny] == 1)
                        {
                            check[nx][ny] = check[current.x][current.y] + 1;
                            q.push({nx, ny, 1});
                        }
                    }
                    else if (current.state == 1)
                    {
                        if (graph[nx][ny] == 0)
                        {
                            check[nx][ny] = check[current.x][current.y] + 1;
                            q.push({nx, ny, 1});
                        }
                    }
                }
            }
        }
    }
}
int main()
{

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int tmp;
            scanf("%1d", &graph[i][j]);
        }
    }

    vector<int> ans_min;
    bfs();
    int ans_tmp = check[n][m];
    if (ans_tmp != 0)
        ans_min.push_back(ans_tmp);
    fill(&check[0][0], &check[1001][1001] + 1, 0);
    bfs2();
    ans_tmp = check[n][m];
    if (ans_tmp != 0)
        ans_min.push_back(ans_tmp);
    if (ans_min.size() == 0)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", *min_element(ans_min.begin(), ans_min.end()));
    }
}