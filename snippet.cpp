
#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n, x, y;
        cin >> m >> n >> x >> y;
        x -= 1;
        y -= 1;
        bool ok = false;
        for (int k = x; k < (n * m); k += m)
        {
            cout << "possible k " << k << " > " << k % n << " \n";
            if (k % n == y)
            {
                cout << k + 1 << '\n';
                ok = true;
                break;
            }
        }
        if (!ok)
        {
            cout << -1 << '\n';
        }
    }
    return 0;
}
