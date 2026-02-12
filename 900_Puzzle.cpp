#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-11-03
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, x, c = 0, s = 1e6, d, t, m;
    cin >> n >> m;
    vector<ll> vc(m);
    for (ll i = 0; i < m; i++)
    {
        cin >> vc[i];
    }
    sort(vc.begin(), vc.end());

    for (ll i = 0; i <= (m - n); i++)
    {
        x = vc[i + n - 1] - vc[i];
        if (x < s)
        {
            s = x;
        }
    }
    cout << s << endl;

    return 0;
}