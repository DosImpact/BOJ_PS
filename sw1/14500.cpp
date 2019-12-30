//https://www.acmicpc.net/problem/14500
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int field[501][501];

int a[19][3][2] = {
    {{0, 1}, {0, 2}, {0, 3}},
    {{1, 0}, {2, 0}, {3, 0}},
    {{1, 0}, {1, 1}, {1, 2}},
    {{0, 1}, {1, 0}, {2, 0}},
    {{0, 1}, {0, 2}, {1, 2}},
    {{1, 0}, {2, 0}, {2, -1}},
    {{0, 1}, {0, 2}, {-1, 2}},
    {{1, 0}, {2, 0}, {2, 1}},
    {{0, 1}, {0, 2}, {1, 0}},
    {{0, 1}, {1, 1}, {2, 1}},
    {{0, 1}, {1, 0}, {1, 1}},
    {{0, 1}, {-1, 1}, {-1, 2}},
    {{1, 0}, {1, 1}, {2, 1}},
    {{0, 1}, {1, 1}, {1, 2}},
    {{1, 0}, {1, -1}, {2, -1}},
    {{0, 1}, {0, 2}, {-1, 1}},
    {{0, 1}, {0, 2}, {1, 1}},
    {{1, 0}, {2, 0}, {1, 1}},
    {{1, 0}, {2, 0}, {1, -1}},

};
int main()
{
    int max = -1;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int ele;
            cin >> ele;
            field[i][j] = ele;
        }
    }
    int ans = -1;
    //��� n,m�� ���鼭
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            //a�� 19�� ���ҵ��� ���ƺ�
            for (int k = 0; k < 19; k++)
            {
                int tmp_max = field[i][j];
                //���� ������, a�� 3���� ���� ���鼭
                for (int t = 0; t < 3; t++)
                {
                    int nx = i + a[k][t][0];
                    int ny = j + a[k][t][1];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    {
                        break;
                    } //���� üũ | ��üũ �� ���ϱ�
                    tmp_max += field[nx][ny];
                }
                // �ִ밪�̸�ans�� �ֱ�.
                if (ans == -1 || ans < tmp_max)
                {
                    ans = tmp_max;
                }
            }
        }
    }
    cout << ans;
}