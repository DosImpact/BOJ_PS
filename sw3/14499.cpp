//https://www.acmicpc.net/problem/14499
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<int> dice(6);
int graph[21][21];
int n, m, x, y, k;
vector<int> kv;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
void printDice()
{
    for (auto _dice : dice)
    {
        cout << _dice << " ";
    }
    cout << "\n";
}
int main()
{
    cin >> n >> m >> x >> y >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
        }
    }
    for (int i = 0; i < k; i++)
    {
        int tmp;
        cin >> tmp;
        kv.push_back(tmp);
    }
    //�Է� �Ϸ�
    for (int i = 0; i < kv.size(); i++)
    {
        //��ɾ� �ϳ��� ������.
        int cmd = kv[i] - 1;
        //cout << cmd << " ";

        //���� ĭ���� ���� ������ ��ŵ , ���� �ִٸ�,
        // �ֻ����� ������ ��, �ֻ����� ������ �ٱ����� �̵���ų �� ����. ���� �ٱ����� �̵���Ű���� �ϴ� ��쿡�� �ش� ����� �����ؾ� �ϸ�, ��µ� �ϸ� �� �ȴ�.
        int nx = x + dx[cmd];
        int ny = y + dy[cmd];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
            continue;

        //�ֻ��� �̵���Ű��.
        vector<int> tmp_dice(6, 0);
        tmp_dice = dice;
        if (cmd == 0)
        {
            tmp_dice[1] = dice[4];
            tmp_dice[3] = dice[5];
            tmp_dice[4] = dice[3];
            tmp_dice[5] = dice[1];
        }
        else if (cmd == 1)
        {
            tmp_dice[1] = dice[5];
            tmp_dice[3] = dice[4];
            tmp_dice[4] = dice[1];
            tmp_dice[5] = dice[3];
        }
        else if (cmd == 2)
        {
            tmp_dice[0] = dice[1];
            tmp_dice[1] = dice[2];
            tmp_dice[2] = dice[3];
            tmp_dice[3] = dice[0];
        }
        else if (cmd == 3)
        {
            tmp_dice[0] = dice[3];
            tmp_dice[1] = dice[0];
            tmp_dice[2] = dice[1];
            tmp_dice[3] = dice[2];
        }
        dice = tmp_dice; //�ֻ��� �ٲٱ�.

        if (graph[nx][ny] == 0)
        {
            //�̵��� ĭ�� ���� �ִ� ���� 0�̸�, �ֻ����� �ٴڸ鿡 ���� �ִ� ���� ĭ�� ����ȴ�.
            graph[nx][ny] = dice[3];
        }
        else
        {
            //  0�� �ƴ� ��쿡�� ĭ�� ���� �ִ� ���� �ֻ����� �ٴڸ����� ����Ǹ�, ĭ�� ���� �ִ� ���� 0�� �ȴ�.
            dice[3] = graph[nx][ny];
            graph[nx][ny] = 0;
        }
        x = nx;
        y = ny;
        cout << dice[1] << "\n";
    }
}