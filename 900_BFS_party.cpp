#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll bfs(ll st, vector<vector<ll>> &adj, ll n)
{
    vector<bool> vis(n, false);
    vector<ll> lv(n, -1);
    queue<ll> q;
    vis[st] = true;
    q.push(st);
    lv[st] = 1; 

    while (!q.empty())
    {
        ll node = q.front();
        q.pop();
        for (ll x : adj[node])
        {
            if (!vis[x])
            {
                vis[x] = true;
                lv[x] = lv[node] + 1;
                q.push(x);
            }
        }
    }

    ll mx = 0;
    for (ll i = 0; i < n; i++)
        mx = max(mx, lv[i]);
    return mx;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<vector<ll>> adj(n);
    vector<ll> roots;

    for (ll i = 0; i < n; ++i)
    {
        ll u;
        cin >> u;
        if (u == -1)
        {
            roots.push_back(i); 
        }
        else
        {
            u--; 
            adj[u].push_back(i);
        }
    }

    ll answer = 0;
    for (ll root : roots)
    {
        answer = max(answer, bfs(root, adj, n));
    }

    cout << answer << '\n';

    return 0;
}
