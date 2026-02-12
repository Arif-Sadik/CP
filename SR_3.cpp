#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-10-10
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, m, t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;

        vector<vector<ll>> g(n), rg(n);
        for (ll i = 0; i < m; i++)
        {
            ll u, v;
            cin >> u >> v;
            --u;
            --v;
            g[u].push_back(v);
            rg[v].push_back(u);
        }

        vector<ll> order, comp(n, -1);
        vector<char> vis(n, 0);

        for (ll i = 0; i < n; i++)
        {
            if (vis[i])
                continue;
            stack<pair<ll, ll>> st;
            st.push({i, 0});
            vis[i] = 1;

            while (!st.empty())
            {
                ll u = st.top().first;
                ll &idx = st.top().second;
                if (idx < (ll)g[u].size())
                {
                    ll v = g[u][idx++];
                    if (!vis[v])
                    {
                        vis[v] = 1;
                        st.push({v, 0});
                    }
                }
                else
                {
                    order.push_back(u);
                    st.pop();
                }
            }
        }

        ll ccnt = 0;
        for (ll i = n - 1; i >= 0; i--)
        {
            ll v = order[i];
            if (comp[v] != -1)
                continue;
            stack<ll> st;
            st.push(v);
            comp[v] = ccnt;
            while (!st.empty())
            {
                ll u = st.top();
                st.pop();
                for (ll w : rg[u])
                {
                    if (comp[w] == -1)
                    {
                        comp[w] = ccnt;
                        st.push(w);
                    }
                }
            }
            ccnt++;
        }

        vector<ll> cSize(ccnt, 0);
        for (ll i = 0; i < n; i++)
            cSize[comp[i]]++;

        vector<vector<ll>> dag(ccnt);
        unordered_set<unsigned long long> used;
        used.reserve(m * 2);

        for (ll u = 0; u < n; u++)
        {
            for (ll v : g[u])
            {
                ll cu = comp[u], cv = comp[v];
                if (cu == cv)
                    continue;
                unsigned long long key = ((unsigned long long)cu << 32) | cv;
                if (used.insert(key).second)
                {
                    dag[cu].push_back(cv);
                }
            }
        }

        vector<ll> now(ccnt, -1e9), nxt(ccnt, -1e9);
        for (ll i = 0; i < ccnt; i++)
            now[i] = cSize[i];

        ll ans = *max_element(now.begin(), now.end());

        for (ll step = 2; step <= k; step++)
        {
            fill(nxt.begin(), nxt.end(), -1000000000);
            for (ll u = 0; u < ccnt; u++)
            {
                if (now[u] < 0)
                    continue;
                for (ll v : dag[u])
                {
                    nxt[u] = max(nxt[u], cSize[u] + now[v]);
                }
            }
            for (ll i = 0; i < ccnt; i++)
                ans = max(ans, nxt[i]);
            swap(now, nxt);
        }

        cout << ans << '\n';
    }

    return 0;
}
