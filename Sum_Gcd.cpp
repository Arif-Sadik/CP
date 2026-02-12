#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2026-02-01
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    ll s = 0;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            ll g = __gcd(i, j);
            for (ll k = 1; k <= n; k++)
            {
                s += __gcd(g, k);
            }
        }
    }
    cout << s << "\n";

    return 0;
}