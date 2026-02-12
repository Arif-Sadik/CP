#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-12-30
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, x, c, s, d, t;
    cin >> n >> t;
    vector<ll> r(n);
    vector<ll> p(n);
    bool pos = true;
    for (ll i = 0; i < n; i++)
    {
        cin >> r[i];
        if (r[i] >= t)
        {
            pos = false;
        }
        else
        {
            p[i] = (t - 1) / r[i];
        }
    }
    if (!pos)
    {
        cout << 0 << endl;
        return 0;
    }
    ll lw = 1, hi = 1e9;
    ll ans = 1;
    while (lw <= hi)
    {
        ll mid = (hi + lw) / 2;
        ll lt = mid - 1;
        ll nd = 0;
        bool ok = true;

        for (ll i = 0; i < n; i++)
        {
            nd += lt / p[i];
            if (nd > lt)
            {
                ok = false;
                break;
            }
        }

        if (ok)
        {
            ans = mid;
            lw = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}