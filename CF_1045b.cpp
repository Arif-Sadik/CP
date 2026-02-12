#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-08-26

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, x, c, s, d, t;
    cin >> t;
    while (t--)
    {
        c = 0, s = 0, d = 0;
        cin >> n >> k;
        vector<ll> vc(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> vc[i];
        }

        ll G = vc[0];
        for (ll i = 1; i < n; ++i)
        {
            G = gcd(G, vc[i]);
        }

        if (G > 1)
        {
            for (ll i = 0; i < n; ++i)
            {
                if (i)
                    cout << ' ';
                cout << vc[i];
            }
            cout << '\n';
            continue;
        }
        if (k % 2 == 1)
        {
            for (ll i = 0; i < n; ++i)
            {
                if (vc[i] % 2 != 0)
                    vc[i] += k;
            }
            for (ll i = 0; i < n; ++i)
            {
                if (i)
                    cout << ' ';
                cout << vc[i];
            }
            cout << '\n';
            continue;
        }

        x = k + 1;
        ll p = 0;
        for (ll d2 = 2; d2 * d2 <= x; ++d2)
        {
            if (x % d2 == 0)
            {
                p = d2;
                break;
            }
        }
        if (p == 0)
        {
            p = x;
        }
        for (ll i = 0; i < n; ++i)
        {
            ll m = vc[i] % p;
            vc[i] += m * k;
        }

        for (ll i = 0; i < n; ++i)
        {
            if (i)
                cout << ' ';
            cout << vc[i];
        }
        cout << '\n';
    }

    return 0;
}
