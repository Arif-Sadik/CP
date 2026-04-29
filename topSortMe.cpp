#include <bits/stdc++.h>
#define ll long long
using namespace std;

void dfs(vector<vector<ll>> &graph, ll u, stack<ll> &st, vector<ll> &vis)
{
    vis[u] = 1;
    for (ll v : graph[u])
        if (vis[v] == 0)
            dfs(graph, v, st, vis);
    st.push(u);
}

// Md. Arif Sadik Molla
// Date: 2026-02-22
int main()
{
    ll n, e;
    cin >> n >> e;
    vector<vector<ll>> graph(n);
    for (ll i = 0; i < e; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    vector<ll> vis(n, 0);
    stack<ll> st;
    for (ll i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            dfs(graph, i, st, vis);
        }
    }

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}