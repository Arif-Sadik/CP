#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-08-21
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, x, c, s, d, t;
    vector<ll> vc(21, 1);
    for (ll i = 1; i < 21; i++)
    {
        vc[i] = vc[i - 1] * 3;
    }

    cin >> t;
    while (t--)
    {
        s = 0;
        cin >> n;
        c = 0;
        while (n > 0)
        {
            d = n % 3;
            if (d > 0)
            {
                if (c == 0)
                {
                    k = 3;
                }
                else
                {
                    k = vc[c + 1] + (ll)c * vc[c - 1];
                }
                s += (ll)d * k;
            }
            n /= 3;
            c++;
        }
        cout << s << '\n';
    }

    return 0;
}
