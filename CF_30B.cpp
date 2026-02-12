#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-11-06
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, c, s, d, t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        bool found = false;
        ll x, y;

        for (int i = 0; i < n && !found; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                ll rem = a[j] % a[i];
                if (rem % 2 == 0)
                {
                    x = a[i];
                    y = a[j];
                    found = true;
                    break;
                }
            }
        }

        if (found)
            cout << x << " " << y << "\n";
        else
            cout << -1 << "\n";
    }

    return 0;
}
