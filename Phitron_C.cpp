#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-12-30
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll  k, x, c, s, d, t;
    cin >> t;
    while (t--)
    {
        unsigned long long n;
        cin >> n;
        if (n == 0)
        {
            cout << 0 << "\n";
            continue;
        }
        ll bts = __builtin_popcountll(n);
        unsigned long long ans = (1ULL << (bts - 1));
        cout << ans << "\n";
    }

    return 0;
}