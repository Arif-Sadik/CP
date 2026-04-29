#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2026-04-13
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, x, c, s, d, t, m;
    cin >> t;
    while (t--)
    {
        c = 1, s = 0, d = 0;
        cin >> n >> m;
        vector<ll> vc(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> vc[i];
        }
        bool bl = true;
        for (ll i = 1; i < n; i++)
        {
            if (vc[i] == vc[i - 1])
            {
                c++;
                if (c >= m)
                {
                    bl = false;
                    break;
                }
            }
            else
            {
                c = 1;
            }
        }
        if (bl)
        {
            cout << "Yes\n";
        }
        else
            cout << "No\n";
    }

    return 0;
}