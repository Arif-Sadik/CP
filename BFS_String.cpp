#include <bits/stdc++.h>
using namespace std;

void bfs(int st, vector<vector<int>> &adj, int n,
         vector<bool> &vis, vector<int> &parent,
         vector<int> &level, vector<vector<int>> &level_order) {
    
    queue<int> q;
    vis[st] = true;
    q.push(st);
    parent[st] = -1;
    level[st] = 0;
    level_order[0].push_back(st);

    while (!q.empty()) {
        int node = q.front(); q.pop();
        cout << "Visited: " << node << endl; // index (can map to string later)

        for (int nei : adj[node]) {
            if (!vis[nei]) {
                vis[nei] = true;
                parent[nei] = node;
                level[nei] = level[node] + 1;
                level_order[level[nei]].push_back(nei);
                q.push(nei);
            }
        }
    }
}

void print_path(int node, vector<int> &parent, vector<string> &names) {
    if (parent[node] == -1) {
        cout << names[node];
        return;
    }
    print_path(parent[node], parent, names);
    cout << " -> " << names[node];
}

int main() {
    int n, e;
    cin >> n >> e;

    vector<string> names(n);
    unordered_map<string,int> idx; // map string -> index
    for (int i = 0; i < n; i++) {
        cin >> names[i];
        idx[names[i]] = i;
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < e; i++) {
        string u, v;
        cin >> u >> v;
        int a = idx[u], b = idx[v];
        adj[a].push_back(b);
        // adj[b].push_back(a); // uncomment if undirected
    }

    string root_name;
    cin >> root_name;
    int start = idx[root_name];

    vector<bool> vis(n, false);
    vector<int> parent(n, -1);
    vector<int> level(n, -1);
    vector<vector<int>> level_order(n);

    cout << "\nBFS Traversal (indices):\n";
    bfs(start, adj, n, vis, parent, level, level_order);

    cout << "\nPaths from root (" << root_name << "):\n";
    for (int i = 0; i < n; i++) {
        print_path(i, parent, names);
        cout << endl;
    }

    cout << "\nDistances from root (" << root_name << "):\n";
    for (int i = 0; i < n; i++) {
        cout << names[i] << " -> Distance " << level[i] << endl;
    }

    cout << "\nLevel Order:\n";
    for (int i = 0; i < n; i++) {
        if (level_order[i].empty()) break;
        cout << "Level " << i << ":";
        for (int node : level_order[i])
            cout << " " << names[node];
        cout << endl;
    }

    return 0;
}
