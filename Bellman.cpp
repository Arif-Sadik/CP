#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        
        // Relax edges V-1 times
        for (int i = 0; i < V - 1; i++) {
            for (auto it : edges) {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        
        // Check for negative cycles
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                return {-1}; 
            }
        }
        return dist;
    }
};

int main() {
    int V, E, S;
    cout << "Enter number of Vertices (V) and Edges (E): ";
    cin >> V >> E;

    vector<vector<int>> edges;

    cout << "Enter " << E << " edges (Source Destination Weight):" << endl;
    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    cout << "Enter Source Vertex (S): ";
    cin >> S;

    Solution obj;
    vector<int> res = obj.bellman_ford(V, edges, S);

    if (res.size() == 1 && res[0] == -1) {
        cout << "\nNegative Cycle Detected!" << endl;
    } else {
        cout << "\nShortest distances from node " << S << ":" << endl;
        for (int i = 0; i < V; i++) {
            cout << "Node " << i << ": " << res[i] << endl;
        }
    }

    return 0;
}