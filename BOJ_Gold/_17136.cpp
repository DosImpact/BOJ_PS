// https://www.acmicpc.net/problem/17136
#include <iostream>
#include <tuple>
#include <queue>
#include <algorithm>
#include <deque>
#include <vector>
#include <string>
#include <stack>
#define SIZE 10
using namespace std;

int graph[SIZE][SIZE];     //���� �� 0~9
int tmp_graph[SIZE][SIZE]; // ����� ��.

void disCover(int size, int x, int y) //5 5 ������� x,y������ ����  �� ���´�.
{
    for (int i = x; i < x + size; i++)
    {
        for (int j = y; j < y + size; j++)
        {
            tmp_graph[i][j] = 0;
        }
    }
}
void cover(int size, int x, int y) //5 5 ������� x,y������ ���� ���´�.
{
    for (int i = x; i < x + size; i++)
    {
        for (int j = y; j < y + size; j++)
        {
            tmp_graph[i][j] = 1;
        }
    }
}
bool canCover(int size, int x, int y) //���� üũ ~
{
    for (int i = x; i < x + size; i++)
    {
        for (int j = y; j < y + size; j++)
        {
            if (x > 9 || y > 9 || x < 0 || y < 0 || graph[i][j] == 0 || tmp_graph[i][j] == 1)
            {
                return false;
            }
        }
    }
    return true;
}
//���� �����̼� | ������� ���� �� , ���� z�ε��� , ���� �����̼�
int go(int count, int z, vector<int> &cp)
{
    //z�� ������ ������ ���
    if (z == 100)
    {
        cout << "[DEBUG]";
        cout << cp[0] << " " << cp[1] << " " << cp[2] << " " << cp[3] << " " << cp[4] << "\n";
        // for (int i = 0; i < 10; i++)
        // {
        //     for (int j = 0; j < 10; j++)
        //     {
        //         cout << graph[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";
        // cout << "\n";
        // for (int i = 0; i < 10; i++)
        // {
        //     for (int j = 0; j < 10; j++)
        //     {
        //         cout << tmp_graph[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // int tmp;
        // cin >> tmp;
        return count;
    }
    int x = z / 10;
    int y = z % 10;
    if (graph[x][y] == 0)
    { //z�� graph 0�̸� ���
        return go(count, z + 1, cp);
    }
    else if (graph[x][y] == 1 && tmp_graph[x][y] == 1)
    {
        return go(count, z + 1, cp);
    }
    else if (graph[x][y] == 1 && tmp_graph[x][y] == 0)
    { //z graph 1�̸� | 5���� 1���� �����. | ��������, -1 ����
        int min = -1;
        for (int i = 4; i >= 0; i--)
        {
            if (cp[i] > 0)
            {
                if (canCover(i + 1, x, y)) // 5 ������� ����?
                {
                    cp[i] -= 1;
                    cover(i + 1, x, y);
                    int tmp = go(count + 1, z + 1, cp);
                    //FB if ((min == -1 || min > tmp))
                    if (tmp != -1 && (min == -1 || min > tmp)) //tmp �� -1�� �ƴϿ��ߵ�.
                    {
                        min = tmp;
                    }
                    disCover(i + 1, x, y);
                    cp[i] += 1;
                }
            }
        }
        return min; //���� ��� -1�̸� �ȵǴ� ��� | ���� �ְ��� => ����
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> graph[i][j];
        }
    }
    vector<int> cp = {5, 5, 5, 5, 5};
    int ans = go(0, 0, cp);
    cout << ans;
}
/*

0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1 1 1
0 0 0 0 0 0 0 1 1 1
0 0 0 0 0 0 1 1 1 1
0 0 0 0 0 0 1 1 0 0
0 0 0 0 0 0 0 0 0 0

1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 0 1
1 1 1 1 1 1 1 1 1 1



0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 1 1 1 1 1 
0 0 0 0 0 1 1 1 1 1 
0 0 0 0 0 1 1 1 1 1 
0 0 0 0 0 1 1 1 0 1 
0 0 0 0 0 1 1 1 1 1 

*/