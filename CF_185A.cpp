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

        if (n == 1)
            cout << 1 << "\n";
        else if (n == 2)
            cout << 9 << "\n";
        else if (n == 3)
            cout << 29 << "\n";
        else if (n == 4)
            cout << 56 << "\n";
        else
        {
            ll ans = 5 * n * (n - 1) - 5;
            cout << ans << "\n";
        }
    }
    return 0;
}
