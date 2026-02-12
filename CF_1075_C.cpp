#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2026-01-23
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
        if (n % 2 == 0)
            cout << n << " ";
        else
            cout << n - 1 << " ";
        for (ll i = 2; i < n; i++)
        {
            cout << (i ^ 1) << " ";
        }
        cout << 1 << "\n";
    }

    return 0;
}