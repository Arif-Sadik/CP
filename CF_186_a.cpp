#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-12-29
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        string s;
        cin >> n >> s;

        ll c = 0;
        ll d = 4;

        for (ll i = 0; i + 4 <= n; i++)
            if (s.substr(i, 4) == "2025")
                c++;

        for (ll i = 0; i + 4 <= n; i++)
        {
            string cur = s.substr(i, 4);
            ll x = 0;
            for (int j = 0; j < 4; j++)
                if (cur[j] != "2026"[j])
                    x++;
            d = min(d, x);
        }

        cout << min(c, d) << '\n';
    }

    return 0;
}
