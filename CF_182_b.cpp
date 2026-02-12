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
        vector<ll> p(n);
        vector<bool> av(n + 1, false);
        vector<ll> z;
        vector<ll> npos;

        for (ll i = 0; i < n; i++)
        {
            cin >> p[i];
            if (p[i] != 0)
            {
                av[i + 1] = true;
            }
            else if (p[i] == 0)
            {
                z.push_back(i);
            }
            if (p[i] != i + 1)
            {
                npos.push_back(i);
            }
        }
        vector<ll> mis;
        for (ll i = 1; i <= n; i++)
        {
            if (!av[i])
            {
                mis.push_back(i);
            }
        }
        k = z.size();
        ll ans;
        if (k == 0)
        {
            if (!npos.empty())
            {
                ll mn = *min_element(npos.begin(), npos.end());
                ll mx = *max_element(npos.begin(), npos.end());
                ans = mx - mn + 1;
            }
            else
                ans = 0;
        }
        else if (k == 1)
        {
            ll z = z[0];
            s = mis[0];
            if (s == z + 1)
            {
                if (!npos.empty())
                {
                    int mn = *min_element(npos.begin(), npos.end());
                    int mx = *max_element(npos.begin(), npos.end());
                    ans = mx - mn + 1;
                }
                else
                    ans = 0;
            }
            else
            {
                if (npos.empty())
                    ans = 1;
                else
                {
                    int mn = min(z, *min_element(npos.begin(), npos.end()));
                    int mx = max(z, *max_element(npos.begin(), npos.end()));
                    ans = mx - mn + 1;
                }
            }
        }
        else
        { 
            int mn = *min_element(z.begin(), z.end());
            int mx = *max_element(z.begin(), z.end());
            if (!npos.empty())
            {
                mn = min(mn, *min_element(npos.begin(), npos.end()));
                mx = max(mx, *max_element(npos.begin(), npos.end()));
            }
            ans = mx - mn + 1;
        }

        cout << ans << '\n';
    }
}

return 0;
}