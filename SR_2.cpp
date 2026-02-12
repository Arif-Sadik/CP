#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-10-10

ll sad(const string &str, ll tap)
{
    ll n = (ll)str.size();
    const ll mx = 1e9;
    vector<ll> vc(n);
    for (ll i = 0; i < n; ++i)
    {
        vc[i] = str[i] - '0';
    }

    auto toggle = [&](ll idx)
    {
        if (idx - 1 >= 0)
        {
            vc[idx - 1] ^= 1;
        }
        vc[idx] ^= 1;
        if (idx + 1 < n)
        {
            vc[idx + 1] ^= 1;
        }
    };

    ll c = 0;
    if (tap)
    {
        toggle(0);
        c++;
    }

    for (ll i = 1; i < n; ++i)
    {
        ll pv = ((i - 1) % 2 == 0) ? 0 : 1;
        if (vc[i - 1] != pv)
        {
            toggle(i);
            c++;
        }
    }

    ll ls = ((n - 1) % 2 == 0) ? 0 : 1;
    if (n > 0 && vc[n - 1] != ls)
    {
        return mx;
    }
    return c;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k, x, d, t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> n >> s;

        ll ans0 = sad(s, 0);
        ll ans1 = sad(s, 1);
        ll ans = min(ans0, ans1);
        if (ans >= (ll)1e9)
        {
            cout << -1 << '\n';
        }
        else
        {
            cout << ans << '\n';
        }
    }

    return 0;
}
