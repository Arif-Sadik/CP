#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2026-04-07
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, x, c, s, d, t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        vector<ll> a(n + 1);
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        ll p;
        cin >> p;
        ll tg = a[p];
        vector<ll> b(n + 2, 0);
        for (ll i = 1; i <= n; i++)
        {
            if (a[i] != tg)
            {
                b[i] = 1;
            }
        }
        ll l = 0;
        for (ll i = 0; i < p; i++)
        {
            if (b[i] != b[i + 1])
            {
                l++;
            }
        }
        ll r = 0;
        for (ll i = p; i <= n; i++)
        {
            if (b[i] != b[i + 1])
            {
                r++;
            }
        }
        cout << max(l, r) << "\n";
    }

    return 0;
}