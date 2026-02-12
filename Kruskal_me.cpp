#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> edges;

bool comp(vector<int> edge1, vector<int> edge2)
{
    return edge1[2] <= edge2[2];
}

class DSU
{
    int par[1000];  // parent
    int rank[1000]; // rank   tends to depth!!

public:
    DSU(int n)
    {
        for (int i = 0; i < n; i++)
        {
            par[i] = i;
            rank[i] = 0;
        }
    }
    int findPar(int u)
    {
        if (par[u] == u)
        {
            return u;
        }
        par[u] = findPar(par[u]); // Recursive to find par
    }

    void unionSet(int u, int v)
    {
        u=findPar(u);
        v=findPar(v);

        if (u==v)
        {
            return;
        }

        if (rank[u]>rank[v])
        {
            par[v]=u;
        }
        else if (rank[u]<rank[v])
        {
             par[u]=v;
        }
        else {
            par[u]=v;
            rank[v]++;
        }
    }
};

int main()
{
    int n, m;
    cin >> n >> m; // edge, node

    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w}); // Set of data
    }

    sort(edges.begin(), edges.end(), comp);

    int cost = 0;

    DSU dsu(n);
    vector<vector<int>>mst_edges; //Min spanning tree
    //mst create korte j edge gula use korsi
    for(auto edge: edges)
    {
        int u=edge[0];
        int v=edge[1];
        int w=edge[2];

        if(dsu.findPar(u)!=dsu.findPar(v))
        {
            cost++;
            dsu.unionSet(u,v);
            mst_edges.push_back(edge);  // {u,v,w}
        }
    }
    cout<<cost;

    return 0;
}