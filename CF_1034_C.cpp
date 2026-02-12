#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, x, c, s, d, t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<ll> vc(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> vc[i];
        }
        //  if (n == 1)
        //      cout << "1";

        vector<bool> lessL(n, false);
        ll cmin = vc[0];
        lessL[0] = true;
        for (ll i = 1; i < n; i++)
        {
            if (vc[i] < cmin)
            {
                lessL[i] = true;
                cmin = vc[i];
            }
        }

        vector<bool> greatR(n, false);
        ll cmax = vc[n - 1];
        greatR[n - 1] = true;
        for (ll i = n - 2; i >= 0; i--)
        {
            if (vc[i] > cmax)
            {
                greatR[i] = true;
                cmax = vc[i];
            }
        }

        for (ll i = 0; i < n; i++)
        {
            if (lessL[i] || greatR[i])
            {
                cout << "1";
            }
            else
                cout << "0";
        }
        cout << endl;
    }

    return 0;
}