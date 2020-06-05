//https://www.acmicpc.net/problem/1966
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
using namespace std;
//�⺻���� ���.n����
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> v(n);
        //���� �Է¹޽��ϴ�.
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        //�������� �߿䵵 ������ ū ������ ������ ���մϴ�.
        int bcouter = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[m] < v[i])
            {
                bcouter++;
            }
        }
        if (bcouter == 0)
        {
            //�տ������� ��¼����� ���մϴ�.
            for (int i = 0; i < m; i++)
            {
                if (v[m] == v[i])
                    bcouter++;
            }
            cout << bcouter + 1 << "\n";
            continue;
        }
        else
        {
            // ����� �߿䵵���� �ϳ� ū���� �ڿ������� ã�� �ε����� ���մϴ�.
            int diff = 100;
            for (int i = 0; i < n; i++)
            {
                int tmp_diff = v[i] - v[m];
                if (tmp_diff > 0 && tmp_diff < diff)
                {
                    diff = tmp_diff;
                }
            }
            int onemorebig = n - 1;
            while (onemorebig >= 0)
            {
                int tmp_diff = v[onemorebig] - v[m];
                if ((tmp_diff) == diff)
                {
                    break;
                }
                onemorebig--;
            }
            int ans = bcouter;
            //cout << "bcouter " << bcouter << " onemorebigidx " << onemorebig << " diff " << diff << "\n";
            // �� �ε��� ���� ������, ó������ �ε������� �����̽� �մϴ�.
            for (int i = onemorebig; i < n; i++)
            {
                if (v[i] == v[m])
                    ans++;
                if (i == m)
                {
                    cout << ans << "\n";
                    break;
                }
            }
            for (int i = 0; i < onemorebig; i++)
            {
                if (v[i] == v[m])
                    ans++;
                if (i == m)
                {
                    cout << ans << "\n";
                    break;
                }
            }
        }
    }
}