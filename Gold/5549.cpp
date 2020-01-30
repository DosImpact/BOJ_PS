//https://www.acmicpc.net/problem/5549
/*
1���õ� DP�� ���� : �ð��ʰ�
2���õ� ��Ÿ������ x �� ���� : 3�ʴ�� �ð��ʰ� : 3kN �̹Ƿ� , 3�ʰ� ����....
3���õ� ��Ÿ������ x,y �� ���� : k �ð� �ɸ� ���!!
*/

#include <iostream>
#include <tuple>
#include <queue>
#include <algorithm>
#include <deque>
#include <vector>
#include <string>
#include <stack>
#define SIZE 1001
using namespace std;
int Jgraph[SIZE][SIZE];
int Ograph[SIZE][SIZE];
int Igraph[SIZE][SIZE];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    vector<string> graph;
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        graph.push_back(tmp);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char e = graph[i - 1][j - 1];
            if (e == 'J')
            {
                Jgraph[i][j] = 1;
            }
            else if (e == 'O')
            {
                Ograph[i][j] = 1;
            }
            else if (e == 'I')
            {
                Igraph[i][j] = 1;
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {

            Jgraph[i][j] += Jgraph[i][j - 1];
            Ograph[i][j] += Ograph[i][j - 1];
            Igraph[i][j] += Igraph[i][j - 1];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {

            Jgraph[i][j] += Jgraph[i - 1][j];
            Ograph[i][j] += Ograph[i - 1][j];
            Igraph[i][j] += Igraph[i - 1][j];
        }
    }
    for (int i = 0; i < k; i++)
    {
        int ux, uy, dx, dy;
        cin >> ux >> uy >> dx >> dy;
        int J = 0, O = 0, I = 0;
        cout << Jgraph[dx][dy] - Jgraph[dx][uy - 1] - Jgraph[ux - 1][dy] + Jgraph[ux - 1][uy - 1] << " ";
        cout << Ograph[dx][dy] - Ograph[dx][uy - 1] - Ograph[ux - 1][dy] + Ograph[ux - 1][uy - 1] << " ";
        cout << Igraph[dx][dy] - Igraph[dx][uy - 1] - Igraph[ux - 1][dy] + Igraph[ux - 1][uy - 1] << "\n";
    }
}