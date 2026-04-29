#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2026-04-07
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, x, c, s, d, t;
    cin >> t;
    while (t--)
    {
        s = 0;
        cin >> n >> k;

        for (ll i = 0; i < n; i++)
        {
            cin >> x;
            s += x;
        }

        if (s % 2 != 0 || (n * k) % 2 == 0)
        {
            cout << "yES\n";
        }
        else
        {
            cout << "nO\n";
        }
    }

    return 0;
}