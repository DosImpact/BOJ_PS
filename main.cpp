//https://www.acmicpc.net/problem/1012
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
<<<<<<< HEAD
int graph[10][10];
int c1[10][10]; // �� üũ
int c2[10][10]; // �� üũ
int c3[10][10]; // ������ üũ
void printGraph()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
}
int squre(int x, int y)
{
    return ((x / 3) * 3) + (y / 3);
}
//fb)��Ʈ��ŷ �̱⶧����, �����͸� �ϴ� �����ߵǰ� + | ���ϰ��� false�̸� ����ؼ� Ž���� �����Ѵ�.
bool go(int z)
{
    if (z == 81)
    {
        //�� �ξ�����,����ϰ� �����ϱ�
        printGraph();
        return true;
    }
    //���� z�� �Ѿ�µ�,
    //�׷����� �̹� 0�ƴ� ���ڸ�, ���� ����
    int x = z / 9;
    int y = z % 9;
    if (graph[x][y] != 0)
    {
        return go(z + 1);
    }
    else
    {
        //�ƴ϶�� 1���� 9���� ���鼭 check�� ���� �� ����� ������, �α�.
        for (int i = 1; i <= 9; i++)
        {
            if ((c1[x][i] == 0) && (c2[y][i] == 0) && (c3[squre(x, y)][i] == 0))
            {
                c1[x][i] = c2[y][i] = c3[squre(x, y)][i] = 1;
                graph[x][y] = i;
                //go���� ��Ʈ��ŷ�� �����ϴ� ����.
                if (go(z + 1))
                {
                    return true;
                }
                //fb) �׷����� 0���� ������־�ߵȴ�. �׷���. ��Ʈ��ŷ �ߴ� ������ ��������. �ȱ׷���, graph�� ���ڰ� ���Ƽ� �׳� �������� �Ѿ�ݾ�..
                graph[x][y] = 0;
                c1[x][i] = c2[y][i] = c3[squre(x, y)][i] = 0;
            }
        }
        return false;
    }
=======
int a, p;
int check[10000001];
int pow(int a, int p)
{
    int ans = 1;
    for (int i = 1; i <= p; i++)
    {
        ans *= a;
    }
    return ans;
>>>>>>> 2994ee1974dc28748a47225485fd5ca50dbbb7ff
}
// int nextNode(int x)
// {
//     int sum = 0;
//     do
//     {
//         int a = x / 10;
//         int b = x % 10;
//         sum += pow(b, p);
//     } while (a != 0);
//     return sum;
// }
int nextNode(int x)
{
<<<<<<< HEAD
    //���䱸 �Է¹ޱ�.
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int tmp;
            cin >> tmp;
            graph[i][j] = tmp;
            if (tmp != 0)
            {
                // i�࿡ 3�� �ִ�.
                c1[i][tmp] = 1;
                // j���� 3�� �ִ�.
                c2[j][tmp] = 1;
                // i,j���� �簢���ȿ� 3�� �ִ�.
                c3[squre(i, j)][tmp] = 1;
            }
        }
    }
    go(0);
    //printGraph();
    //cout << squre(8, 8);
}
/*
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
*/
=======
    int sum = 0;
    while (x != 0)
    {
        sum += pow(x % 10, p);
        x = x / 10;
    }
    return sum;
}
void dfs(int x, int checkNum)
{
    //���� ��带 üũ���ְ�, ���� ��带 ���ؿ´�.
    check[x] = checkNum;
    int next = nextNode(x);
    //cout << "DEBUG" << x << " -> " << next << "\n";
    if (check[next] == 0)
    { //���� ��尡 �湮 ���ߴٸ� �������� �湮�ϰ�, üũ�� +1
        dfs(next, checkNum + 1);
    }
    else
    {
        //�湮�ߴٸ� ��������� üũ�ѹ����� -1 ���
        cout << check[next] - 1;
        return;
    }
}
int main()
{
    cin >> a >> p;
    dfs(a, 1);
    //cout << pow(2, 3) << "\n";
    //cout << nextNode(a);
}
>>>>>>> 2994ee1974dc28748a47225485fd5ca50dbbb7ff
