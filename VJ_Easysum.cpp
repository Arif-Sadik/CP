#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-11-01
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, x, a, b, c, s = 0, d, t;

    ll mx = 1e6 + 1; // Num_Div_Sieve
    vector<ll> counter(mx, 0);
    for (ll i = 1; i < mx; i++)
    {
        for (ll j = i; j < mx; j += i)
        {
            counter[j]++;
        }
    }

    cin >> a >> b >> c;

    for (ll i = 1; i <= a; i++)
    {
        for (ll j = 1; j <= b; j++)
        {
            for (ll k = 1; k <= c; k++)
            {
                s += counter[i * j * k];
            }
        }
    }
    cout << s << endl;

    return 0;
}