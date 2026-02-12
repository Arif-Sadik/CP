#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
	public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V, 1e9);

        dist[S] = 0;
        pq.push({0, S});

        while(!pq.empty()) { 
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it : adj[node]) {
                int edgeWeight = it[1];
                int adjNode = it[0];

                if(dis + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};

int main() {
    int V, E, S;
    cout << "Enter number of Vertices (V) and Edges (E): ";
    cin >> V >> E;

    // Adjacency list
    vector<vector<int>> adj[V];

    cout << "Enter " << E << " edges (Source Destination Weight):" << endl;
    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        // For Directed Graph:
        adj[u].push_back({v, w});
        
        // Un-comment the line below if the graph is UNDIRECTED:
        // adj[v].push_back({u, w}); 
    }

    cout << "Enter Source Vertex (S): ";
    cin >> S;

    Solution obj;
    vector<int> res = obj.dijkstra(V, adj, S);

    cout << "\nShortest distances from node " << S << ":" << endl;
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << ": " << res[i] << endl;
    }

    return 0;
}