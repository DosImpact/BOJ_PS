//https://www.acmicpc.net/problem/14889
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n; //20���� �۴�.
int graph[20][20];
int ans = 2100000000;
//õõ�� ���ڸ� �ϳ��� ������, ���� �������� �򸱼��� �ִµ�, ����ó���� ������.
// �� �ε���(idx  ==n�̸� �ٰ�), �����̳� �ΰ�
void go(int idx, vector<int> &con1, vector<int> &con2)
{
    //�ٸ��� ���
    if (idx == n)
    {

        //���� ���� ���� ���.
        if (con1.size() != (n / 2) || con2.size() != (n / 2))
            return;
        // cout << "\n�ٸ���!!\n";
        // for (auto &k : con1)
        // {
        //     cout << k;
        // }
        // cout << "\n";
        // for (auto &k : con2)
        // {
        //     cout << k;
        // }
        //���� �ջ갪�� ���غ���.
        int t1 = 0, t2 = 0;
        for (int i = 0; i < (n / 2); i++)
        {
            for (int j = 0; j < (n / 2); j++)
            {
                if (i == j)
                    continue;
                t1 += graph[con1[i]][con1[j]];
                t2 += graph[con2[i]][con2[j]];
            }
        }

        //�ּҶ�� ans �ֱ�
        int diff = t1 - t2;
        if (diff < 0)
            diff = -diff;
        //cout << diff << "\n";
        if (ans > diff)
        {
            ans = diff;
        }
        return;
    }
    //    //���)con1�� idx�� �ֺ��� go �ٽ� ����
    con1.push_back(idx);
    go(idx + 1, con1, con2);
    con1.pop_back();
    //con2�� �õ�
    con2.push_back(idx);
    go(idx + 1, con1, con2);
    con2.pop_back();

    return;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }
    vector<int> con1;
    vector<int> con2;
    go(0, con1, con2);
    cout << ans;
}