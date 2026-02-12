#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-09-08
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, k, x, c, s, d, t;
    ll a, b;
    cin >> t;
    while (t--)
    {
        c = 0, s = 0, d = 0;
        cin >> k >> x;
        s = pow(2, k + 1);
        
        //s = 1LL << (k+1);
        c = s / 2;
        if (x == c)
        {
            cout << 0 << endl
                 << endl;
            continue;
        }
        a = x;
        b = s - x;

        vector<ll> vc;
        for (ll i = 0; i < 121; i++)
        {
            if (a == c)
            {
                break;
            }
            if (a < b)
            {
                vc.push_back(1);
                b -= a;
                a += a;
            }
            else
            {
                vc.push_back(2);
                a -= b;
                b += b;
            }
        }
        reverse(vc.begin(), vc.end());
        cout << vc.size() << endl;
        for (ll i = 0; i < vc.size(); i++)
        {
            cout << vc[i] << " ";
        }
        cout << endl;
    }

    return 0;
}