
#include<bits/stdc++.h>
using namespace std;

void bfs(int st, vector<vector<int>>& adj, int n)
{
    vector<bool>vis(n,false);
    queue<int> q;
    vis[st]=true;
    q.push(st);

    while (!q.empty())
    {
        int node=q.front();
        q.pop();
        cout<<node<<" ";
        for (int neighbour: adj[node])
        {
            if (!vis[neighbour])
            {
                vis[neighbour]=true;
                q.push(neighbour);
            }
        }

    }

}



int main()
{
    int n, e;
    cin>>n>>e;
    vector<vector<int>> adj(n);
    for(int i=0; i<e; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u); //undirected    so 2 way..
    }
    int start;
    cin>>start;
    cout<<"BFS Travarsal: ";

    bfs(start, adj, n);

}
