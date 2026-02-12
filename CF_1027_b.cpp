#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

int main()
{
    ll n, k, x, c, s, d, t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        ll c0 = 0;
        for (char c : s)
            if (c == '0')
                c0++;
        ll c1 = n - c0;
        ll p = n / 2;
        ll b = p - k;

        if (b < 0 || c0 < b || c1 < b)
        {
            cout << "NO\n";
            continue;
        }

        c0 -= b;
        c1 -= b;
        ll g = c0 / 2 + c1 / 2;

        cout << (g >= k ? "YES\n" : "NO\n");
    }
    return 0;
}