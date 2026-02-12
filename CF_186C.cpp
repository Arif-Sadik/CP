#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-12-29

ll count(ll n, vector<ll> &v1, vector<ll> &v2)
{
    ll valid = 0;
    for (ll i = 0; i < n; i++)
    {
        bool ok = true;
        for (ll k = 0; k < n; k++)
        {
            if (v1[k] >= v2[(k + i) % n])
            {
                ok = false;
                break;
            }
        }
        if (ok)
            valid++;
    }
    return valid;
}

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
        vector<ll> a(n), b(n), c(n);

        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (ll i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        for (ll i = 0; i < n; i++)
        {
            cin >> c[i];
        }
        ll ab = count(n, a, b);
        ll bc = count(n, b, c);
        cout << ab * bc * n << endl;
    }

    return 0;
}