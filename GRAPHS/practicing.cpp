#include<bits/stdc++.h>
using namespace std;

bool dfs(int node,vector<int> adj[],vector<int> &color){
    if(color[node] == -1) color[node] = 1;
    for(auto a:adj[node]){
        if(color[a] == -1){
            color[a] = 1 - color[node];
            if(dfs(a,adj,color)) return true;
        }
        else if(color[a] == color[node]) return true;
    }
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
        adj[v].push_back(u);
    }
    vector<int> color(n+1,-1);
    for(int i=1;i<=n;i++){
        if(color[i] == -1) if(dfs(i,adj,color)){
            cout<<"NOT A BIPARTITE EXISTS";
            return 0;
        }
    }
    cout<<"BIPARTITE";
    return 0;
}

// Not a Bapartite input
// 8 8
// 1 2
// 2 3
// 2 8
// 3 4
// 4 5
// 5 8
// 5 6
// 6 7


// A Bapartite input
// 8 8
// 1 2
// 2 3
// 2 8
// 3 4
// 4 6
// 5 8
// 5 6
// 6 7