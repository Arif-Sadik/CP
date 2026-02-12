#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-09-21
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, e;
    cin >> n >> e;
    vector<ll> vc(n, 0);
    ll x = e;
    while (x--)
    {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        vc[u]++;
        ;
        vc[v]++;
    }

    ll c1 =0, c2 =0, c = 0;

    for (ll i = 0; i < n; i++)
    {
        if (vc[i] == 1)
            c1++;
        else if (vc[i] == 2)
        {
            c2++;
        }
        else if (vc[i] > 2)
        {
            c++;
        }
    }

    if (c == 1 && c2 == 0 && c1 ==n-1)
    {
        cout << "star topology";
    }
    else if (c2 == n && c1 == 0 && c == 0)
    {
        cout << "ring topology";
    }
    else if (c1 == 2 && c2 == n-2 && c == 0)
        cout << "bus topology";
    else
        cout << "unknown topology";

    return 0;
}