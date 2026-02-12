#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-11-29
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
        vector<ll> f(2 * n + 2, 0);

        for (ll i = 0; i < 2 * n; i++)
        {
            cin >> x;
            f[x]++;
        }

        for (ll i = 1; i <= 2 * n; i++)
        {
            if (f[i] == 0)
                continue;
            if (f[i] % 2 != 0)
                c++;
            else
                s++;
        }

        ll y = min(s, n);

        if (c == 0 && (y % 2 != n % 2))
        {
            y--;
        }

        cout << c + 2 * y << "\n";
    }
    return 0;
}
