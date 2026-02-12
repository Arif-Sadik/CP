#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<char> vis;

void dfs(int u) {
    vis[u] = 1;
    for (int v : g[u]) {
        if (!vis[v]) dfs(v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> n >> m)) return 0;

    g.assign(n + 1, {});
    vis.assign(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if (m != n - 1) {
        cout << "NO\n";
        return 0;
    }

    if (n == 0) { 
        cout << "NO\n";
        return 0;
    }

    dfs(1);

    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}
