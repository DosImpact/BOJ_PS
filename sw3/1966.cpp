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
        deque<pair<int, int>> dq;
        for (int i = 0; i < n; i++)
        {
            int tmp, ismark = 0;
            cin >> tmp;
            if (i == m)
                ismark = 1;
            dq.push_back(make_pair(tmp, ismark));
        }
        int printCouter = 0;
        bool finished = false;
        while (!finished)
        {
            auto max = max_element(dq.begin(), dq.end());
            //���� �պκ��� ����, �ִ밪�̶��,
            auto current = dq.front();
            dq.pop_front();
            //��������, ī���� ����, ���� ��ũ���ִٸ�, ������ ���
            if (current.first == (*max).first)
            {
                printCouter++;
                if (current.second == 1)
                {
                    finished = true;
                }
            }
            else //�ƴ϶�� �ٽ� �ֱ�.
            {
                dq.push_back(current);
            }
        }
        cout << printCouter << "\n";
    }
}