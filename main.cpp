//https://www.acmicpc.net/problem/14889
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
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