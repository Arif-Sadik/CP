#include<bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2026-04-18

bool comp(vector<int>& edge1, vector<int>& edge2)
{
    return edge1[2] < edge2[2]; 
}

class DSU
{
    vector<int> par;
    vector<int> rank;

public:
    DSU(int n)
    {
        par.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            par[i] = i;
        }
    }
    
    int findPar(int u)
    {
        if (par[u] == u)
        {
            return u;
        }
        return par[u] = findPar(par[u]); 
    }

    void unionSet(int a, int b)
    {
        a = findPar(a);
        b = findPar(b);

        if (a == b)
        {
            return;
        }

        if (rank[a] > rank[b])
        {
            par[b] = a;
        }
        else if (rank[a] < rank[b])
        {
             par[a] = b;
        }
        else 
        {
            par[a] = b;
            rank[b]++;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> edges;

    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edges.push_back({a, b, w, i}); 
    }

    sort(edges.begin(), edges.end(), comp);

    long long cost = 0; 
    DSU dsu(n);
    
    vector<string> result(m, "NO");

    for(auto edge : edges)
    {
        int a = edge[0];
        int b = edge[1];
        int w = edge[2];
        int id = edge[3];

        if(dsu.findPar(a) != dsu.findPar(b))
        {
            cost += w; 
            dsu.unionSet(a, b);
            result[id] = "YES"; 
        }
    }

    for (int i = 0; i < m; i++)
    {
        cout << result[i] << "\n";
    }
    
    cout << "Minimum total cost: " << cost << "\n";

    return 0;
}