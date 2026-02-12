#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-11-28
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
        vector<ll> vc(n);

        for (ll i = 0; i < n; i++)
        {
            cin >> vc[i];`
            s += vc[i];
            if (vc[i] == 0)
                c++;
        }
        d = n - c;
        cout << min(d, s - (n - 1)) << "\n";
    }

    return 0;
}
