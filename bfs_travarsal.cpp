#include<bits/stdc++.h>
#define ll long long
using namespace std;

void bfs(ll st, vector<vector<ll>> &adj, ll n)
{
    vector<bool> vis(n, false);
    queue<ll> q;
    vis[st] = true;
    q.push(st);

    while (!q.empty())
    {
        ll node = q.front(); q.pop();
        cout << node << " ";
        for (ll x : adj[node])
        {
            if (!vis[x])
            {
                vis[x] = true;
                q.push(x);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, e;
    cin >> n >> e;
    vector<vector<ll>> adj(n);

    for (ll i = 0; i < e; ++i)
    {
        ll u, v;
        cin >> u >> v;
        // **for 0-based input, do NOT decrement**
        if (u < 0 || u >= n || v < 0 || v >= n) {
            cerr << "Invalid edge: " << u << " " << v << '\n';
            return 0;
        }
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll start;
    cin >> start;

    // ✅ BOUNDS CHECK FOR START NODE
    if (start < 0 || start >= n) {
        cerr << "Invalid start node: " << start << '\n';
        return 0;
    }

    cout << "BFS: ";
    bfs(start, adj, n);
    cout << '\n';

    return 0;
}
