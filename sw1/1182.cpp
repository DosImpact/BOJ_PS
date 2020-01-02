//https://www.acmicpc.net/problem/1182
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

int n, s;
void printNumber(vector<int> a)
{
    for (auto &k : a)
    {
        cout << k << " ";
    }
    cout << "\n";
}
bool isSumS(vector<int> a)
{
    int sum = 0;
    for (int i = 0; i < a.size(); i++)
    {
        sum += a[i];
    }
    if (sum == s)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// ���� ������ | ,������� �� ���ڵ�, ���� �� ����,
int go(vector<int> &number, vector<int> current, int nextNumber)
{
    int row = 0;
    //fb)��� ���ϴٰ� 0�� �Ǵ� ��쵵 �־�.
    //������ ���� ����غ��� ������ 1�� ��ȯ
    if (isSumS(current) && number.size() == nextNumber)
    {
        return 1;
    }
    //�� ���� ������ 0 ��ȯ
    if (!isSumS(current) && number.size() == nextNumber)
    {
        return 0;
    }
    //���.
    current.push_back(number[nextNumber]);
    row += go(number, current, nextNumber + 1);
    current.pop_back();
    row += go(number, current, nextNumber + 1);

    return row;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> s;
    vector<int> number;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        number.push_back(ele);
    }
    vector<int> current;
    int ans = go(number, current, 0);
    if (s == 0)
    {
        cout << ans - 1;
    }
    else
    {
        cout << ans;
    }
}