//https://www.acmicpc.net/problem/1759
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
bool check(string s)
{
    int ja = 0;
    int mo = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            mo++;
        }
        else
        {
            ja++;
        }
    }
    return (ja >= 2 && mo >= 1);
}
//������ ����, ������� �����,  ����Ҽ��ִ¾��ĺ�, ���ѹ�,
void go(int n, string current, vector<char> &alpha, int choice)
{
    //���ڿ��� ���̰� �ϼ��� �Ǹ� �˻���  check��� �׸��� ����
    if (current.size() == n)
    {
        if (check(current))
        {
            cout << current << "\n";
        }
        return;
    }
    // choice�� �����µ� ���ڿ��� ���̰� �����ϸ� �׳� ����
    if (alpha.size() == choice)
    {
        return;
    }
    go(n, current + alpha[choice], alpha, choice + 1);
    go(n, current, alpha, choice + 1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int l, c;
    cin >> l >> c;
    vector<char> alpha;
    for (int i = 0; i < c; i++)
    {
        char ele;
        cin >> ele;
        alpha.push_back(ele);
    }
    sort(alpha.begin(), alpha.end());
    go(l, "", alpha, 0);
}