#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2026-01-23
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, x, s, t;
    cin >> t;
    while (t--)
    {
        s = 0;
        ll x;
        cin >> n >> x;

        ll s = 0;
        ll max = -2e18;
        for (ll i = 0; i < n; i++)
        {
            ll a, b, c;
            cin >> a >> b >> c;
            s += a * (b - 1);
            ll d = (a * b) - c;
            if (d > max)
            {
                max = d;
            }
        }

        if (s >= x)
        {
            cout << 0 << "\n";
        }
        else
        {
            if (max <= 0)
            {
                cout << -1 << "\n";
            }
            else
            {
                ll need = x - s;
                ll rb = (need + max - 1) / max;
                cout << rb << "\n";
            }
        }
    }

    return 0;
}