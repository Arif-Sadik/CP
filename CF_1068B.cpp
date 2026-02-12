#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-12-05
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, x, c, s, d, t;
    cin >> t;
    while (t--)
    {
        c = 0, s = 0, d = 0;
        ll mx = 0;
        ll mn = 0;
        cin >> n;
        vector<ll> a(n), b(n);
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
            ll rmx = mx - a[i];
            ll bmx = b[i]-mn;
            ll new_mx = max(rmx, bmx);

            ll rmn = mn - a[i];
            ll bmn =   b[i]-mx;
            ll new_mn = min(rmn, bmn);

            mx = new_mx;
            mn = new_mn;
        }
        cout << mx << endl;
    }

    return 0;
}