#include <iostream>
#include <algorithm>
using namespace std;

int check[10000001];

int pow(int a, int b)
{
    int ans = 1;
    while (b--)
    {
        ans *= a;
    }
    return ans;
}
int next(int a, int p)
{
    int ans = 0;
    while (a != 0)
    {
        //FB. ������ ���� ������ �ڿ��� ���� ©�󳻴� ����̴�, string���� ��ȯ�ؼ� ó���ϴ� ����� ����.
        ans += pow(a % 10, p);
        a = a / 10;
    }
    return ans;
}
int length(int a, int p, int checknum)
{
    check[a] = checknum;
    int b = next(a, p);
    if (check[b] != 0)
    {
        return check[b] - 1;
    }
    else
    { //FB.return�� ��������, �Լ��� ����ǰ� ����� ������ �ȵ���..
        return length(b, p, checknum + 1);
    }
}
int main()
{
    int a, p;
    cin >> a >> p;
    cout << length(a, p, 1);
}