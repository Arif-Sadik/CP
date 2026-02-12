#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-09-08
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, k, x, c, s, d, t;
    cin >> t;
    while (t--)
    {
        c = 0, s = 0, d = 0;
        cin >> n >> m;
        vector<ll> vc(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> vc[i];
        }
        sort(vc.rbegin(), vc.rend());

        for (ll i = 0; i < min(n, m); i++)
        {
            s += vc[i] * (m - i);
        }
        cout << s << endl;
    }

    return 0;
}