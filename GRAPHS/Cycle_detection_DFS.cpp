// Cycle Detection in a graph using DFS

#include<bits/stdc++.h>
using namespace std;

bool cycle_dfs(int node,vector<int> &vis,vector<int> adj[],int parent){
    vis[node] = 1;
    for(auto a:adj[node]){
        if(!vis[a]){
            if(cycle_dfs(a,vis,adj,node)) return true;
        }
        else if(a!=parent){
            return true;
        }
    }
    return false;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    vector<int> vis(n+1,0);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(cycle_dfs(i,vis,adj,-1)){
                cout<<"Cycle Exists";
                return 0;
            }
        }
    }
    cout<<"Cycle Doesn't Exists";
    return 0;
}

// INPUT
// 6 6
// 1 2
// 2 3
// 2 6
// 3 4
// 3 5
// 5 6