#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-10-31
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, x, c, s, d, t;
    cin >> t;
    ll mx = 1e9 + 7;
    while (t--)
    {
        c = 1, s = 0, d = 0;
        cin >> n;
        for (ll i = 1; i <= n; i++)
        {
            c = c * i % mx;
        }
        cout<<c<<endl;
    }

    return 0;
}