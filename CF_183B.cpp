#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-10-06
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        if (k == n)
        {
            for (ll i = 0; i < n; i++)
                cout << '-';
            cout << '\n';
            continue;
        }

        ll a = 0, b = 0, c = 0;
        for (char ch : s)
        {
            if (ch == '0')
                ++a;
            else if (ch == '1')
                ++b;
            else
                ++c;
        }

        ll l = a;
        ll h = n - 1 - b;

        ll ml = a + c;
        ll mh = n - 1 - b - c;

        for (ll i = 0; i < n; i++)
        {
            if (l > h)
            {
                cout << '-';
            }
            else if (i < l || i > h)
            {
                cout << '-';
            }
            else if (i >= ml && i <= mh)
            {
                cout << '+';
            }
            else
            {
                cout << '?';
            }
        }
        cout << '\n';
    }

    return 0;
}
