//https : //www.acmicpc.net/problem/2982
#include <iostream>
#include <tuple>
#include <queue>
#include <algorithm>
#include <deque>
#include <vector>
#include <string>
#include <stack>
#include <string>
#define SIZE 1001
using namespace std;

int n, m, a, b, k, g;
int glist[SIZE];   //���� �湮 ����Ʈ
int gweight[SIZE]; // glist[i] glist[i+1] �ɸ��� �ð� : gweight[i] ~ gweight[i+1]
int graph[SIZE][SIZE];
int graphKing[SIZE][SIZE];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //�Է� ó��
    cin >> n >> m >> a >> b >> k >> g;
    for (int i = 0; i < g; i++)
    {
        cin >> glist[i];
    }
    for (int i = 0; i < m; i++)
    {
        int u, v, l;
        cin >> u >> v >> l;
        graph[u][v] = l;
        graph[v][u] = l;
    }
    //ŷ �׷��� -1�� �ʱ�ȭ
    //glist���� �ϳ���
    gweight[0] = 0;
    for (int i = 1; i < g; i++)
    {
        gweight[i] = gweight[i - 1] + graph[glist[i - 1]][glist[i]];
        //cout << gweight[i] << " ";
    }
}