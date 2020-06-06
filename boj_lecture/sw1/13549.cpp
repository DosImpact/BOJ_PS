//https://www.acmicpc.net/problem/13549
#include <iostream>
#include <tuple>
#include <queue>
#include <algorithm>
#include <vector>
#define SIZE 100001
using namespace std;
int d[SIZE];

int main()
{
    fill(&d[0], &d[0] + SIZE, -1);
    int n, k;
    cin >> n >> k;
    vector<int> v;
    queue<int> q1;
    queue<int> q2;
    v[0];
    q1.push(n);
    d[n] = 0;
    while (!q1.empty())
    {
        //���� ��ġ ����
        int now = q1.front();
        q1.pop();
        if (now == k)
        {
            cout << d[now];
            return 0;
        }
        // �����̵� x => x*2    // ���� üũ | �湮 ���� | ,q1�� ����ġ ���� ��� �־��ش�.
        if (now * 2 <= SIZE)
        {
            if (d[now * 2] == -1)
            {
                d[now * 2] = d[now];
                q1.push(now * 2);
            }
        }
        // �ȱ� x => x+1 // ���� üũ / �湮 ���� / q2.�� ����ġ + 1
        if (now + 1 <= SIZE)
        {
            if (d[now + 1] == -1)
            {
                d[now + 1] = d[now] + 1;
                q2.push(now + 1);
            }
        }
        // x => x - 1  // ���� üũ / �湮 ���� / q2.�� ����ġ + 1
        if (now - 1 >= 0)
        {
            if (d[now - 1] == -1)
            {
                d[now - 1] = d[now] + 1;
                q2.push(now - 1);
            }
        }
        //q1�� ������ٸ� , q1�� 2�� ��ü �� q2�� ��� �α�
        if (q1.empty())
        {
            q1 = q2;
            q2 = queue<int>();
        }
    }
}