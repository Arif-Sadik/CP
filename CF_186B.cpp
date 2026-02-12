#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-12-29

ll ck(ll c1, ll c2)
{
    ll h = 0;
    ll cost = 1;
    while (true)
    {
        if (h % 2 == 0)
        {
            if (c1 >= cost)
            {
                c1 -= cost;
            }
            else
            {
                break;
            }
        }
        else
        {
            if (c2 >= cost)
            {
                c2 -= cost;
            }
            else
            {
                break;
            }
        }
        h++;
        cost *= 2;
    }
    return h;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        ll ans1 = ck(a, b);
        ll ans2 = ck(b, a);
        cout << max(ans1, ans2) << endl;
    }

    return 0;
}