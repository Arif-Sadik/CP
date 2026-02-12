#include <bits/stdc++.h>
using namespace std;

void bfs(int st, vector<vector<int>> &adj, vector<bool> &vis,
         vector<int> &parent, vector<int> &level, vector<int> &root)
{
    queue<int> q;
    q.push(st);
    vis[st] = true;
    parent[st] = -1;
    level[st] = 0;
    root[st] = st;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << "Visited: " << node << endl;

        for (int nei : adj[node])
        {
            if (!vis[nei])
            {
                vis[nei] = true;
                parent[nei] = node;
                level[nei] = level[node] + 1;
                root[nei] = st; // mark which component root it belongs to
                q.push(nei);
            }
        }
    }
}

void print_path(int node, vector<int> &parent)
{
    if (parent[node] == -1)
    {
        cout << node;
        return;
    }
    print_path(parent[node], parent);
    cout << "->" << node;
}

int main()
{
    int n, e;
    cin >> n >> e;

    vector<vector<int>> adj(n + 1); // 1-based indexing
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected
    }

    vector<bool> vis(n + 1, false);
    vector<int> parent(n + 1, -1);
    vector<int> level(n + 1, -1);
    vector<int> root(n + 1, -1);

    int components = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            components++;
            bfs(i, adj, vis, parent, level, root);
        }
    }

    cout << "\nNumber of disconnected components: " << components << "\n";

    cout << "\nPaths from root:\n";
    for (int i = 1; i <= n; i++)
    {
        print_path(i, parent);
        cout << endl;
    }

    cout << "\nDistances:\n";
    for (int i = 1; i <= n; i++)
    {
        cout << "Node " << i << " -> Distance " << level[i]
             << " from root " << root[i] << endl;
    }

    return 0;
}
