#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-10-28
int main()
{

    ll mx = 1e6 + 1;
    vector<ll> counter(mx, 0);
    for (ll i = 1; i < mx; i++)
    {
        for (ll j = i; j < mx; j += i)
        {
            counter[j]++;
        }
    }

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, x, c, s, d, t;
    cin >> t;
    while (t--)
    {
        c = 0, s = 0, d = 0;
        cin >> n;
        cout << counter[n] << endl;
    }

    return 0;
}

