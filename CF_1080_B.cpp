#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2026-02-15
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        bool p = true;

        for (ll i = 1; i <= n; i++)
        {
            ll m;
            cin >> m;

            ll u = m;
            ll v = i;

            while (u % 2 == 0)
            {
                u /= 2;
            }
            while (v % 2 == 0)
            {
                v /= 2;
            }
            if (u != v)
            {
                p = false;
            }
        }

        if (p)
            cout << "YeS\n";
        else
            cout << "No\n";
    }

    return 0;
}