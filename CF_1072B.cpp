#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2026-01-12
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--)
    {
        ll s, k, m;
        cin >> s >> k >> m;

        if (s <= k)
        {
            ll rem = m % k;
            cout << max(0LL, s - rem) << "\n";
        }
        else
        {
            ll i = m / k;
            ll rem = m % k;

            if (i % 2 == 0)
            {
                cout << max(0LL, s - rem) << "\n";
            }
            else
            {
                cout << max(0LL, k - rem) << "\n";
            }
        }
    }

    return 0;
}