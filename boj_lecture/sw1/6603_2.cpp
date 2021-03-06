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
//고를 숫자들 , 현재까지 만든조합 , 다음 선택지.
void go(vector<int> &number, vector<int> current, int nextNumber)
{
    //FB, 다 만든경우를 먼저 따져야한다.
    //다 만든경우, 현재까지 만든 사이즈가 6이야, && next넘버가 없을지언정 답이 될수있다.
    if (current.size() == 6)
    {
        printNumber(current);
        return;
    }
    //다 못만든경우, 더이상 nextNumber가 없어.
    if (number.size() == nextNumber)
    {
        return;
    }

    //계속
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