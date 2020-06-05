//https://www.acmicpc.net/problem/1018
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#define SIZE 51
using namespace std;

char graph[SIZE][SIZE];
int n, m;
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
        }
    }
    //������ Ž�� ������ ���Ѵ�.
    int xs = n - 7;
    int ys = m - 7;
    //cout << xs << " " << ys;
    int ans_min = -1;
    for (int i = 0; i < xs; i++)
    {
        for (int j = 0; j < ys; j++)
        { //���� ������ ���鼭
            for (int k = 0; k < 2; k++)
            { //�׷��� �ϳ��� �����ϰ�
                int changeCouter = 0;
                char graphCopy[SIZE][SIZE];
                copy(&graph[0][0], &graph[0][0] + SIZE * SIZE, &graphCopy[0][0]);
                //�������� �ٸ� ���ϋ���?
                if (k == 1)
                {
                    graphCopy[i][j] == 'W' ? graphCopy[i][j] = 'B' : graphCopy[i][j] = 'W';
                }

                // 0���� ���� ó���� �Ѵ�.
                for (int dx = i + 1; dx < i + 8; dx++) //fb for���� i�� �ǵ�Ⱦ�...//fb) +8 ��ŭ�� Ž���� �ؾ���..
                {
                    //�ش� �κ��� ���� ������ �ٲ��ְ�, ���� ���� �ƴϸ� ���
                    if (graphCopy[dx - 1][j] == graphCopy[dx][j])
                    {
                        changeCouter += 1;
                        //fb)�̷��� �ٲٸ� �Ȱ���..
                        //graphCopy[dx][j] = graphCopy[dx - 1][j];
                        graphCopy[dx][j] == 'W' ? graphCopy[dx][j] = 'B' : graphCopy[dx][j] = 'W';
                    }
                }
                // 0�� �����͸� ������ �� �ึ�� ü������ �׸���.
                //fb) +8 ��ŭ�� Ž���� �ؾ���..
                for (int dx = i; dx < i + 8; dx++)
                {
                    for (int dy = j + 1; dy < j + 8; dy++)
                    {
                        if (graphCopy[dx][dy] == graphCopy[dx][dy - 1])
                        {
                            changeCouter += 1;
                            graphCopy[dx][dy] == 'W' ? graphCopy[dx][dy] = 'B' : graphCopy[dx][dy] = 'W';
                        }
                    }
                }
                // �مR �κ��� �� ���� ���Ѵ�.
                // cout << "\n";
                // for (int i = 0; i < n; i++)
                // {
                //     for (int j = 0; j < m; j++)
                //     {
                //         cout << graphCopy[i][j];
                //     }
                //     cout << "\n";
                // }
                //cout << "changeCouter " << changeCouter << "<- ";
                if (ans_min == -1 || ans_min > changeCouter)
                {
                    ans_min = changeCouter;
                }
            }
        }
    }
    cout << ans_min;
    //cout << "ans_min " << ans_min << "<- ";
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << graphCopy[i][j];
    //     }
    //     cout << "\n";
    // }
}
/*
9 9
WWWWWWWWW
WWWWWWWWW
WWWWWWWWW
WWWWWWWWW
WWWWWWWWW
WWWWWWWWW
WWWWWWWWW
WWWWWWWWW
WWWWWWWWW
*/