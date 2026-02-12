#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-11-06

bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.first != b.first)
    {
        return a.first < b.first;
    }
    else
    {
        return a.second > b.second;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, k, x, c, s, d, t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;

        vector<ll> sword(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> sword[i];
        }
        vector<ll> b(m), c(m);
        for (ll i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        for (ll i = 0; i < m; i++)
        {
            cin >> c[i];
        }
        vector<pair<ll, ll>> pr(m);
        for (ll i = 0; i < m; i++)
        {
            pr[i] = {b[i], c[i]};
        }
        sort(sword.begin(), sword.end());
        sort(pr.begin(), pr.end(), cmp);

        k = 0;
        vector<bool> kld(m, false); // morse
        for (ll i = 0; i < n; i++)
        {
            ll cur = sword[i];
            while (1)
            {
                ll best_i = -1;
                ll best_rw = -1;

                for (ll j = 0; j < m; j++)
                {
                    if (!kld[j] && pr[j].first <= cur && pr[j].second > best_rw)
                    {
                        best_rw = pr[j].second;
                        best_i = j;
                    }
                }

                if (best_i == -1)
                    break;

                kld[best_i] = true;
                k++;
                if (best_rw > cur)
                {
                    cur = best_rw;
                }
            }
        }
        cout << k << "\n";
    }

    return 0;
}