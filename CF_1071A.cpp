#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-12-23
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, x, c, s, d, t;
    cin >> t;
    while (t--)
    {
        c = 0, s = 0, d = 0;
        cin >> k >> x;
        if (x == 1)
        {
            cout << k + 1 << endl;
        }
        else if (k == 1)
        {
            cout << x + 1 << endl;
        }
        else
            cout << x * k + 1 << endl;
    }

    return 0;
}