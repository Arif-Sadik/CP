#include<bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-10-12

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, x, c, s, d, t;
    cin >> t;
    while (t--)
    {
        c = 0; 
        s = 0; 
        d = 0;
        cin >> n;

        bool ok = false;

        for (ll id = 1; id <= 30; ++id)
        {
            if (n >= (1LL << id))
            {
                continue;
            }

            bool pal = true;
            ll half = id / 2;

            for (ll j = 0; j < half; ++j)
            {
                ll bi = (n >> j) & 1LL;
                ll bj = (n >> (id - 1 - j)) & 1LL;

                if (bi != bj)
                {
                    pal = false;
                    break;
                }
            }

            if (!pal)
            {
                continue;
            }

            if ((id & 1) && (((n >> (id / 2)) & 1LL) != 0))
            {
                continue;
            }

            ok = true;
            break;
        }

        if (ok)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}
