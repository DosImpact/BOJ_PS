//1707

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> graph[20001];
int check[20001];

bool dfs(int x, int c)
{
    check[x] = c;
    for (int i = 0; i < graph[x].size(); i++)
    {
        int node = graph[x][i];
        if (check[node] == 0)
        {
            //FB1.��� for���� �ߴܽ�Ű��, dfs�� �۵���Ű�ݾ�
            //return dfs(node,3-c);.0
            //�̳༮�� �ش� ���ǿ� ������ �Լ� �ߴ� false��ȯ / �ƴϸ� keep
            if (dfs(node, 3 - c) == false)
            {
                return false;
            }
        }
        else if (check[node] == c)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cases;
    cin >> cases;

    while (cases--)
    {
        int n, m;
        cin >> n >> m;

        fill(&check[0], &check[20001 + 1], 0);
        for (int i = 1; i <= n; i++)
        {
            graph[i].clear();
        }

        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        bool Isbi = true;
        for (int i = 1; i <= n; i++)
        {
            if (check[i] == 0)
            {
                if (!dfs(i, 1))
                {
                    Isbi = false;
                }
            }
        }
        if (Isbi)
        {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }
}