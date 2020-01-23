//https : //www.acmicpc.net/problem/14226
#include <iostream>
#include <tuple>
#include <queue>
#include <algorithm>
#include <cstring>
#define SIZE 1001
using namespace std;
int d[1001][1001];

int main()
{
    //����� ���ϴ� �̸�Ƽ�ܼ�,
    int k;
    cin >> k;
    fill(&d[0][0], &d[0][0] + SIZE * SIZE, -1); //fB). 2���� �迭 �ʱ�ȭ..
    //������ ���¸� �ֱ�.
    queue<pair<int, int>> q;
    q.push({1, 0});
    d[1][0] = 0;
    //0��
    while (!q.empty())
    {
        //������ ���
        int s, c;
        tie(s, c) = q.front();
        q.pop();
        if (d[s][s] == -1) //�湮���� �ʾҴٸ�
        {
            d[s][s] = d[s][c] + 1;
            q.push({s, s});
        }
        if (s + c <= k && d[s + c][c] == -1) //���� üũ �� //�湮���� �ʾҴٸ�
        {
            d[s + c][c] = d[s][c] + 1;
            q.push({s + c, c});
        }
        if (s - 1 > 0 && d[s - 1][c] == -1) //���� üũ �� //�湮���� �ʾҴٸ�
        {
            d[s - 1][c] = d[s][c] + 1;
            q.push({s - 1, c});
        }
    }
    //s+c�� ����üũ�� k ���Ϸ� �ߴ�. ���� d[s][c] , s<= k, c <= k
    //d[k][c] ����
    int ans = -1;
    for (int i = 0; i < k; i++)
    {
        if (d[k][i] != -1 && (ans == -1 || d[k][i] < ans))
        {
            ans = d[k][i];
        }
    }
    cout << ans;
}