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
        c = 0, d = 0;
        ll c0 = 0, c1 = 0, c2 = 0, sum = 0;
        cin >> n >> s;
        vector<ll> vc(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> vc[i];
            sum += vc[i];
            if (vc[i] == 0)
                c0++;
            else if (vc[i] == 1)
                c1++;
            else if (vc[i] == 2)
                c2++;
        }

        if (s - sum < 0 || s - sum == 1)
        {
            for (ll i = 0; i < c0; i++)
            {
                cout << 0 << " ";
            }

            for (ll i = 0; i < c2; i++)
            {
                cout << 2 << " ";
            }
            for (ll i = 0; i < c1; i++)
            {
                cout << 1 << " ";
            }
            // for (ll i = 0; i < c2; i++)
            // {
            //     cout << 2 << " ";
            // }
        }
        else
            cout << -1;

        cout << endl;
    }

    return 0;
}