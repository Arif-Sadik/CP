#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>& graph, int u, stack<int>& st, vector<int>& vis){
    vis[u]=1;
    for(int v:graph[u]){
        if(vis[v]==0){
            dfs(graph, v, st, vis);
        }
    }
    st.push(u);
}
int main(){
    int n,e;
    cin>>n>>e;
    vector<vector<int>>graph(n);
    for(int i=0;i<e;i++){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
    }

    stack<int>st;
    vector<int>vis(n,0);
    for(int i=0;i<n;i++){
        if(vis[i]==0){
            dfs(graph, i, st, vis);
        }
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}