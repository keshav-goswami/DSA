#include<bits/stdc++.h>
using namespace std;
void dfs(int node,int parent,vector<int> adj[],vector<int> &vis,vector<int> &tin,vector<int> &lw,int &timer){
    vis[node] = 1;
    tin[node] = lw[node] = timer++;
    for(int a:adj[node]){
        if(a == parent) continue;
        // Here, the unvisited node is calling dfs for its adjacent nodes and updating the tin and lw 
        if(!vis[a]){
            dfs(a,node,adj,vis,tin,lw,timer);
            // Backtracking 
            lw[node] = min(lw[node],lw[a]);
            if(lw[a] > tin[node]) cout<<node<<" "<<a<<endl;
        }
        // Here, The visited node will check the adacent nodes other than parent and will find the lowest time of arrival in them.
        else{
            lw[node] = min(lw[node],tin[a]);
        }
    }
}
int main(){
    // Input Nodes and Edges 
    int n,m;
    cin>>n>>m;
    // Declaring a Graph
    vector<int> adj[n];
    // Input the edges (UnDirected Graph)
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> tin(n,-1);
    vector<int> lw(n,-1);
    vector<int> vis(n,0);
    int timer = 0;
    cout<<"CRITICAL EDGES:\n";
    for(int i=0;i<n;i++){
        dfs(i,-1,adj,vis,tin,lw,timer);
    }
    return 0;
}

// INPUT 
// 10 11
// 0 1
// 1 2
// 1 4
// 2 3
// 3 4
// 4 5
// 5 6
// 6 7
// 6 9
// 7 8
// 8 9