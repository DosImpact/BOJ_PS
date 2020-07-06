//https://www.acmicpc.net/problem/2504
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
using namespace std;
string in;
int main()
{
    cin >> in; //��ȣ �ְ�
    stack<char> st;
    for (int i = 0; i < in.size(); i++) // ��ȣ�� ���鼭
    {
        //(,[ �� ��쿡�� ������ �ִ´�.
        if (in[i] == '(' || in[i] == '[')
        {
            st.push(in[i]);
        }
        //( X.. ) �ΰ�쿡�� , X..������ �����ְ�, *2�� ���ش�. �߰��� [�� �����ų�, ���°������.
        else
        {
            if (in[i] == ')')
            {
                int X = 0;
                // ( �� ���Ë����� ����. ���ڴ� �����ְ�,
                while (true)
                {
                    if (st.empty() || st.top() == '[')
                    {
                        cout << 0;
                        return 0;
                    }
                    if (st.top() == '(')
                    {
                        st.pop();
                        break;
                    }
                    int t = st.top();
                    X += (t - '0');
                    st.pop();
                }
                X == 0 ? X = 1 : X = X;
                X *= 2;
                st.push(X + '0');
            }
            else if (in[i] == ']')
            {
                int Y = 0;
                // ) �� ���Ë����� ����. ���ڴ� �����ְ�,
                while (true)
                {
                    if (st.empty() || st.top() == '(')
                    {
                        cout << 0;
                        return 0;
                    }
                    if (st.top() == '[')
                    {
                        st.pop();
                        break;
                    }
                    int t = st.top();
                    Y += t - '0';
                    st.pop();
                }
                Y == 0 ? Y = 1 : Y = Y;
                Y *= 3;
                st.push(Y + '0');
            }
        }
    }
    int ans = 0;
    while (!st.empty())
    {
        if (st.top() == '(' || st.top() == '[')
        {
            cout << 0;
            return 0;
        }
        ans += st.top() - '0';
        //cout << st.top() - '0' << " ";
        st.pop();
    }
    cout << ans;
}
