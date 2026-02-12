#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-12-23
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
        vector<ll> vc(n), ab(n - 1);
        for (ll i = 0; i < n; i++)
        {
            cin >> vc[i];
        }
        for (ll i = 0; i < n - 1; i++)
        {
            ab[i] = abs(vc[i + 1] - vc[i]);
        }
        sort(ab.begin(), ab.end());
        for (ll i = 0; i < n - 2; i++)
        {
            s += ab[i];
        }
        cout << s << endl;
    }

    return 0;
}