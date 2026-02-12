#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-12-05
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, x, c, s, d, t;
    cin >> t;
    while (t--)
    {
        c = 0, s = -1, d = 0;
        cin >> n >> k;
        string st;
        cin >> st;

        for (ll i = 0; i < n; i++)
        {
            if (st[i] == '1')
            {
                ll l = i;
                ll r = min(n - 1, i + k);
                if (l > s)
                {
                    c += (r - l + 1);
                    s = r;
                }
                else if (r > s)
                {
                    c += (r - s);
                    s = r;
                }
            }
        }

        cout << n - c << endl;
    }

    return 0;
}