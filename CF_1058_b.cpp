#include <bits/stdc++.h>
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
        c = 0, s = 0, d = 0;
        cin >> n;
        vector<ll> b(n + 1, 0);
        for (ll i = 1; i <= n; ++i)
        {
            cin >> b[i];
        }

        vector<vector<ll>> st(n + 1);//st
        vector<ll> a(n + 1, 0);
        ll nx = 1;
        ll pv = 0;

        for (ll i = 1; i <= n; ++i)
        {
            d = b[i] - pv;
            pv = b[i];
            ll p = i - d;

            ll val;
            if (p == 0)
            {
                val = nx++;
            }
            else
            {
                val = st[p].back();
                st[p].pop_back();
            }

            a[i] = val;
            st[i].push_back(val);
        }

        for (ll i = 1; i <= n; ++i)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    return 0;
}