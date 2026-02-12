#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-11-25
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, x, c, s, d, t;
    cin >> t;
    while (t--)
    {
        c = 0, s = 0, d = 0;
        cin >> n >> k >> x;
        if (x <= k * (2 * n - k + 1) / 2 && x >= (k * (k + 1) / 2))
        {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }

    return 0;
}