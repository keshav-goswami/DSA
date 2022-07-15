// Cycle Detection in a Directed Graph using DFS
#include<bits/stdc++.h>
using namespace std;
bool cycle_dfs(int i,vector<int> &vis,vector<int> &dfs,vector<int> adj[]){
    dfs[i] = 1;
    vis[i] = 1;
    for(auto a:adj[i]){
        if(!vis[a]){
            dfs[a] = 1;
            vis[a] = 1;
            if(cycle_dfs(a,vis,dfs,adj)) return true; 
        }
        else if(dfs[a] && vis[a]) return true;
    }
    dfs[i] = 0;
    return false;
}
int main(){
    // Input Nodes and Edges 
    int n,m;
    cin>>n>>m;
    // Declaring a Graph
    vector<int> adj[n+1];
    // Input the edges (Directed Graph)
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int> vis(n+1,0);
    vector<int> dfsvis(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(cycle_dfs(i,vis,dfsvis,adj)){
                cout<<"Cycle Exists";
                return 0;
            }
        }
    }
    cout<<"Cycle Doesn't Exists";
    return 0;
}

// Input Cycle Exists

// 9 10
// 1 2
// 2 3
// 3 4
// 4 5
// 3 6
// 6 5
// 7 2
// 7 8
// 8 9
// 9 7


// Input Cycle Doesn't Exists

// 9 10
// 1 2
// 2 3
// 3 4
// 4 5
// 3 6
// 6 5
// 7 2
// 7 8
// 8 9
// 7 9