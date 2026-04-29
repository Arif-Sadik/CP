#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2026-04-06

bool safe(ll u, vector<vector<ll>>&vc,vector<ll>&cl,ll c)
{
    for(ll nei:vc[u])
    {
        if(cl[nei]==c)
        {
            return false;
        }
    }
    return true;
}

bool solve(ll u, ll v, ll m, vector<vector<ll>> &vc, vector<ll> &cl)
{
    if (u == v)
    {
        return true;
    }
    for (ll c = 1; c <= m; c++)
    {
        if (safe(u,vc,cl,c))
        {
            cl[u]=c;
            if (solve(u+1,v,m,vc,cl))
            {
                return true;
            }
            cl[u]=0;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll v, e, m;
    cin >> v >> e;

    vector<vector<ll>> vc(v);
    for (ll i = 0; i < e; i++)
    {
        ll x, y;
        cin >> x >> y;
        vc[x].push_back(y);
        vc[y].push_back(x);
    }
    cin >> m;
    vector<ll> cl(v); // color
    if (solve(0, v, m, vc, cl))
    {
        for (ll i = 0; i < v; i++)
        {
            cout << i << " " << cl[i]<<"\n";
        }
    }
    else
        cout << "Relax vai!\n";

    return 0;
}