#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2026-03-13

void multi_source_bfs(ll s, queue<tuple<ll, ll, ll>> &q, vector<vector<ll>> &gp, vector<vector<bool>> &seen, vector<ll> &col, vector<ll> &cost)
{
    while (!q.empty())
    {
        ll town = get<0>(q.front());
        ll type = get<1>(q.front());
        ll dist = get<2>(q.front());
        q.pop();
        for (ll nei : gp[town])
        {
            if (!seen[nei][type] && col[nei] < s)
            {
                seen[nei][type] = true;
                col[nei]++;
                cost[nei] += (dist + 1);
                q.push({nei, type, dist + 1});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, k, s;
    cin >> n >> m >> k >> s;
    vector<ll> g(n + 1);
    vector<vector<ll>> gp(n + 1);
    vector<vector<bool>> seen(n + 1, vector<bool>(k + 1, false)); // town,good
    vector<ll> col(n + 1, 0);
    vector<ll> cost(n + 1, 0);
    queue<tuple<ll, ll, ll>> q; // town, type of good, dist

    for (ll i = 1; i <= n; i++)
    {
        cin >> g[i];
        col[i]++;
        seen[i][g[i]] = true;
        q.push({i, g[i], 0});
    }

    for (ll i = 1; i <= m; i++)
    {
        ll u, v;
        cin >> u >> v;
        gp[u].push_back(v);
        gp[v].push_back(u);
    }
    multi_source_bfs(s, q, gp, seen, col, cost);
    for (ll i = 1; i <= n; i++)
    {
        cout << cost[i] << " ";
    }
    cout << endl;

    return 0;
}