#include <iostream>
#include <vector>

using namespace std;

/**
 * Checks if it's safe to assign color 'c' to vertex 'u'.
 * We only check the neighbors of 'u' in the adjacency list.
 */
bool isSafe(int u, const vector<vector<int>>& adj, const vector<int>& color, int c) {
    for (int neighbor : adj[u]) {
        if (color[neighbor] == c) {
            return false;
        }
    }
    return true;
}

/**
 * Backtracking utility function.
 */
bool solve(int u, int V, int m, const vector<vector<int>>& adj, vector<int>& color) {
    // Base Case: All vertices colored
    if (u == V) return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(u, adj, color, c)) {
            color[u] = c;

            // Move to the next vertex
            if (solve(u + 1, V, m, adj, color)) return true;

            // Backtrack
            color[u] = 0;
        }
    }
    return false;
}

int main() {
    int V, E, m;
    cout << "Enter number of vertices and edges: ";
    if (!(cin >> V >> E)) return 0;

    // Adjacency List: vector of vectors
    vector<vector<int>> adj(V);

    cout << "Enter " << E << " edges (u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        // For undirected graph, add edge both ways
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "Enter number of colors (m): ";
    cin >> m;

    vector<int> color(V, 0);

    if (solve(0, V, m, adj, color)) {
        cout << "\nSolution Found:" << endl;
        for (int i = 0; i < V; i++) {
            cout << "Node " << i << " -> Color " << color[i] << endl;
        }
    } else {
        cout << "\nNo solution exists with " << m << " colors." << endl;
    }

    return 0;
}