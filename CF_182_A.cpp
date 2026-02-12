#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-09-15
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, x, c, s, d, t;
    cin >> t;
    while (t--)
    {
        c = 0, s = 0, d = 0;
        cin >> n;
        vector<ll> vc(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> vc[i];
        }
        vector<ll> p(n + 1, 0);
        for (ll i = 0; i < n; i++)
        {
            p[i + 1] = vc[i] + p[i];
        }
        ll s1, s2, s3;
        bool bol = false;
        for (ll l = 0; l < n - 2; l++)
        {
            for (ll r = l+1; r < n - 1; r++)
            {
                s1 = (p[l + 1] - p[0]) % 3;
                s2 = (p[r + 1] - p[l + 1]) % 3;
                s3 = (p[n] - p[r + 1]) % 3;

                if ((s1 == s2 && s2 == s3) || (s1 != s2 && s1 != s3 && s2 != s3))
                {
                    cout << l + 1 << " " << r + 1 << "\n";
                    bol = true;
                    break;
                }
            }
            if (bol)
                break;
        }
        if (!bol)
        {
            cout << "0 0\n";
        }
    }

    return 0;
}