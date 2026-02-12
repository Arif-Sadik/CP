#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-12-05
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k, x, c, s, d, t;
    cin >> t;

    while (t--)
    {
        c = 0, s = 0, d = 0;

        cin >> n >> k;
        vector<ll> a(n);
        unordered_set<ll> st;
        ll mx = 0;

        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            st.insert(a[i]);
            if (a[i] > mx)
            {
                mx = a[i];
            }
        }

        vector<ll> u(st.begin(), st.end());
        sort(u.begin(), u.end());

        vector<ll> vld(u.size(), 0);

        for (ll i = 0; i < u.size(); i++)
        {
            ll v = u[i];

            if ((k / v) > (mx / v))
            {
                continue;
            }
            bool ok = true;
            for (ll mul = v; mul <= k; mul += v)
            {
                if (!st.count(mul))
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                vld[i] = 1;
            }
        }
        unordered_set<ll> cov;
        vector<ll> B;

        for (ll i = 0; i < u.size(); i++)
        {
            ll v = u[i];

            if (vld[i] == 0)
            {
                continue;
            }

            if (cov.count(v))
            {
                continue;
            }

            B.push_back(v);

            for (ll mul = v; mul <= k; mul += v)
            {
                if (st.count(mul))
                {
                    cov.insert(mul);
                }
            }
        }

        if (cov.size() != st.size())
        {
            cout << -1 << endl;
        }
        else
        {
            cout << B.size() << endl;

            for (ll i = 0; i < B.size(); i++)
            {
                cout << B[i];
                if (i + 1 < B.size())
                {
                    cout << " ";
                }
            }

            cout << endl;
        }
    }

    return 0;
}