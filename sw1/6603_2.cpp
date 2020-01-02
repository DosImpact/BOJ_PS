//https://www.acmicpc.net/problem/6603
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

void printNumber(vector<int> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}
//�� ���ڵ� , ������� �������� , ���� ������.
void go(vector<int> &number, vector<int> current, int nextNumber)
{
    //cout << "DEBUG";
    //printNumber(current);
    //�� ������
    if (current.size() == 6)
    {
        printNumber(current);
        return;
    }
    //�� ��������
    if (number.size() == nextNumber)
    {
        return;
    }

    //���
    current.push_back(number[nextNumber]);
    go(number, current, nextNumber + 1);
    current.pop_back();
    go(number, current, nextNumber + 1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (true)
    {
        int t;
        cin >> t;
        if (t == 0)
            break;
        vector<int> number;
        for (int i = 0; i < t; i++)
        {
            int ele;
            cin >> ele;
            number.push_back(ele);
        }
        vector<int> em;
        go(number, em, 0);
        cout << "\n";
    }
}