#include <bits/stdc++.h>
#define ll long long
using namespace std;

void print_path(ll node, vector<ll> &par)
{
    vector<ll> path;
    while (node != -1)
    {
        path.push_back(node);
        node = par[node];
    }
    reverse(path.begin(), path.end());
    for (ll i = 0; i < path.size(); i++)
    {
        if (i)
            cout << "->";
        cout << path[i];
    }
    cout << endl;
}

void bfs(ll st, vector<vector<ll>> &adj, ll n)
{
    vector<bool> vis(n, false);
    vector<ll> par(n, -1);
    vector<ll> lv(n, -1);
    vector<vector<ll>> lv_order(n);
    queue<ll> q;
    vis[st] = true;
    par[st] = -1;
    lv[st] = 0;
    lv_order[0].push_back(st);
    q.push(st);

    while (!q.empty())
    {
        ll node = q.front();
        q.pop();
        cout << node << " ";
        for (ll x : adj[node])
        {
            if (!vis[x])
            {
                vis[x] = true;
                q.push(x);
                par[x] = node;
                lv[x] = lv[node] + 1;
                lv_order[lv[x]].push_back(x);
            }
        }
    }

    cout << "\nPath from root\n";
    for (ll i = 0; i < n; i++)
    {
        print_path(i, par);
    }

    cout << "\nDistances from root:\n";
    for (int i = 0; i < n; i++)
        cout << "Node " << i << " -> Distance " << lv[i] << endl;

    cout << "\nLevel Order:\n";
    for (int i = 0; i < n; i++)
    {
        if (lv_order[i].empty())
            break;
        cout << "Level " << i << ":";
        for (int node : lv_order[i])
            cout << " " << node;
        cout << endl;
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
        if (u < 0 || u >= n || v < 0 || v >= n)
        {
            cerr << "Invalid edge: " << u << " " << v << '\n';
            return 0;
        }
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll start;
    cin >> start;

    // ✅ BOUNDS CHECK FOR START NODE
    if (start < 0 || start >= n)
    {
        cerr << "Invalid start node: " << start << '\n';
        return 0;
    }

    cout << "BFS: ";
    bfs(start, adj, n);
    cout << '\n';

    return 0;
}
