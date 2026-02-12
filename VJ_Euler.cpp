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
    while (t--)
    {
        c = 0, s = 0, d = 0;
        cin >> n;
        c = n * (n + 1) / 2;
        c *= c;
        s = n * (n + 1) * (2 * n + 1) / 6;
        cout << abs(c - s) << endl;
    }

    return 0;
}