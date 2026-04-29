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
        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        ll ans = 0;
        for (ll i = 0; i < n - 1; i++)
        {
            bool b = false;
            if (a[i] == a[i + 1])
                b = true;
            if (a[i] + a[i + 1] == 7)
                b = true;

            if (b)
            {
                ans++;
                i++;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}