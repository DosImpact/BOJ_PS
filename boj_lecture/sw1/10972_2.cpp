//https://www.acmicpc.net/problem/10972
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
bool next_permu(int *a, int n)
{
    //�迭�� i�� �ں��� ���鼭, i�� 0���� Ŭ������ | a[i] �� �޳༮���� ū ������ ã�´�.
    int i = n - 1;
    while (i > 0 && a[i - 1] >= a[i])
        i--;
    //���� i�� 0 ���ϸ� ���� F
    if (i <= 0)
        return false;
    //�迭�� j�� �ں��� ���鼭, a[i-1]���� ū j�� ã�´�.
    int j = n - 1;
    while (a[i - 1] >= a[j])
        j--;
    //swap i-1 ,j
    swap(a[i - 1], a[j]);
    //�迭�� j�εں��� ���鼭,i�� ������ ���鼭 i��j�� swap �س�����.
    j = n - 1;
    while (i < j)
    {
        swap(a[i], a[j]);
        i++;
        j--;
    }
    return true;
}
int main()
{
    int k[10001];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        k[i] = tmp;
    }
    if (next_permu(k, n))
    {
        for (int i = 0; i < n; i++)
        {
            cout << k[i] << " ";
        }
    }
    else
    {
        cout << "-1";
    }
}