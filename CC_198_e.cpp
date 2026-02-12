#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n, c, t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        string A;
        cin >> A;

        if ((n & (n - 1)) == 0)
        {
            cout << -1 << "\n";
        }
        else
        {
            c = 0;
            for (ll i = 1; i <= n; i++)
            {
                char tg;
                if ((i & (i - 1)) == 0)
                {
                    tg = '1';
                }
                else
                {
                    tg = '0';
                }

                if (A[i - 1] != tg)
                {
                    c = c + 1;
                }
            }
            cout << c << "\n";
        }
    }

    return 0;
}
