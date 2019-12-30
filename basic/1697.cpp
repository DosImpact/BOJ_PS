//https://www.acmicpc.net/problem/1697

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 100001
using namespace std;
int graph[SIZE];
int check[SIZE];
int n, k;
void bfs(int x)
{
    queue<int> q;
    q.push(x);
    //FB. �湮 ������ 0 �� ������ �ȵ���.......n =5 k = 5 �� �ٷ� ã�� 0�� ����ε�, 2�� ���͹���.
    check[x] = 1;
    while (!q.empty())
    {

        int current = q.front();
        q.pop();
        if (current - 1 >= 0 && check[current - 1] == 0)
        {
            q.push(current - 1);
            check[current - 1] = check[current] + 1;
            if (current - 1 == k)
                return;
        }
        if (current + 1 <= SIZE - 1 && check[current + 1] == 0)
        {
            q.push(current + 1);
            check[current + 1] = check[current] + 1;
            if (current + 1 == k)
                return;
        }
        if (current * 2 <= SIZE - 1 && check[current * 2] == 0)
        {
            q.push(current * 2);
            check[current * 2] = check[current] + 1;
            if (current * 2 == k)
                return;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    bfs(n);
    cout << check[k] - 1;
}