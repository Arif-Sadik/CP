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
        c = -1, s = 0, d = 0;
        cin >> n;
        vector<ll> vc(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> vc[i];
        }
        vector<ll> f(n + 1, 0);
        for (ll i = 0; i < n; i++)
        {
            f[vc[i]]++;
            if (f[vc[i]] == 3)
            {
                c = vc[i];
                break;
            }
        }
        cout << c << endl;
    }

    return 0;
}