#include<bits/stdc++.h>
using namespace std;
void bfs(vector<pair<int,int>> adj[],vector<int> &vis,int src,int dest){
    int fwt = 0;
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        if(node == dest) break;
        for(auto a:adj[node]){
            int v = a.first;
            int w = a.second;
            if(!vis[v]){
                q.push(v);
                vis[v] = 1;
                fwt+=w;
            }
        }
    }
    cout<<"SHORTEST PATH: "<<fwt;
}

int main(){
    // Input Nodes and Edges 
    int n,m;
    cin>>n>>m;
    // Declaring a Graph
    vector<pair<int,int>> adj[n+1];
    // Input the edges (UnDirected Graph)
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<int> vis(n+1,0);
    int src = 1;
    int dest = n;
    bfs(adj,vis,src,dest);
    return 0;
}