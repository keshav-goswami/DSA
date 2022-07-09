#include<bits/stdc++.h>
using namespace std;

bool DFS_Bipartite(int i,vector<int> &color,vector<int> adj[]){
    if(color[i] == -1) color[i] = 0;
    for(auto a:adj[i]){
        if(color[a] == -1){
            color[a] = 1 - color[i];
            if(DFS_Bipartite(a,color,adj)) return true;
        }
        else if(color[a] == color[i]){
            return true;
        }
    }
    return false;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    vector<int> color(n+1,-1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(color[i] == -1){
            if(DFS_Bipartite(i,color,adj)){
                cout<<"IT IS NOT A BIPARTITE";
                return 0;
            }
        }
    }
    cout<<"IT IS A BIPARTITE";
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