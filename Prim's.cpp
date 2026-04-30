#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Representing infinity to initialize keys
#define INF INT_MAX

/**
 * Prim's Algorithm Implementation
 * n: number of vertices (V[G])
 * graph: adjacency matrix representing the graph G
 * r: the starting root node
 */
void mstPrim(int n, vector<vector<int>>& graph, int r) {
    // key[u] = infinity: initially, all nodes have an infinite cost to connect to the MST
    vector<int> key(n, INF);    
    
    // p[u] = NULL: stores the parent of each node to track the MST edges
    vector<int> p(n, -1);       
    
    // Q = V[G]: Boolean array where 'true' means the node is still in the "waiting room" (Set Q)
    vector<bool> inQ(n, true);  

    // key[r] = 0: the starting node is assigned a cost of 0 so it is picked first
    key[r] = 0; 

    // The loop continues while Q is not empty (running n times for n vertices)
    for (int count = 0; count < n; count++) {
        
        /* 
           u = ExtractMin(Q):
           Manually searching for the node in Q with the smallest key value.
           In theory, this is where a Priority Queue would be used.
        */
        int u = -1;
        int minKey = INF;
        for (int i = 0; i < n; i++) {
            if (inQ[i] && key[i] < minKey) {
                minKey = key[i];
                u = i;
            }
        }

        // If no node is found, the remaining part of the graph is disconnected
        if (u == -1) break; 

        // Move u from Q to the MST (mark as visited)
        inQ[u] = false; 

        /* 
           for each v in Adj[u]:
           Check all neighbors of the current node u.
        */
        for (int v = 0; v < n; v++) {
            /* 
               Check if:
               1. graph[u][v] != 0: v is actually a neighbor (an edge exists).
               2. v in Q: v is not yet part of the MST.
               3. weight(u,v) < key[v]: we found a cheaper connection to v.
            */
            if (graph[u][v] != 0 && inQ[v] && graph[u][v] < key[v]) {
                p[v] = u;             // p[v] = u: Update parent of v
                key[v] = graph[u][v]; // key[v] = w(u,v): Update minimum cost for v
            }
        }
    }

    // Output section to trace the final edges of the Minimum Spanning Tree
    cout << "Edge \tWeight" << endl;
    for (int i = 0; i < n; i++) {
        // If a node has a parent, it is an edge in the MST
        if (p[i] != -1) {
            cout << p[i] << " - " << i << " \t" << graph[i][p[i]] << endl;
        }
    }
}