//https://www.acmicpc.net/problem/10971
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int w[11][11];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //w�� �Է¹ް�
    int n;
    vector<int> k;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        k.push_back(i);
        for (int j = 0; j < n; j++)
        {
            int ele;
            cin >> ele;
            w[i][j] = ele;
        }
    }
    //������
    sort(k.begin(), k.end());
    //������ �̿��� �ּ� ��� ���ϱ�.
    int ans = -1;
    do
    {
        int tmp_ans = 0;
        bool isOk = true;
        for (int i = 0; i < n - 1; i++)
        {
            //w�� ������ ���� ã����, k�� 0,1,2,3�� ���� ����
            tmp_ans += w[k[i]][k[i + 1]];
            if (w[k[i]][k[i + 1]] == 0)
            {
                isOk = false;
            }
        }
        tmp_ans += w[k[n - 1]][k[0]];
        if (w[k[n - 1]][k[0]] == 0)
        {
            isOk = false;
        }
        // - �ѹ��̶� ���� ���ٸ� ok�� false.
        // ����� �����ؼ� �ּڰ� ���ϱ�.
        if (isOk)
        {
            if (ans == -1 || tmp_ans < ans)
            {
                ans = tmp_ans;
            }
        }
    } while (next_permutation(k.begin(), k.end()));
    cout << ans;
}