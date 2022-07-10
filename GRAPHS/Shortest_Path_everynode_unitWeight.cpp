// Shortest_Path of everynode with unit Weight from source node using BFS

#include<bits/stdc++.h>
using namespace std;

void bfs_path(int n,vector<int> adj[],int src){
    queue<int> q;
    vector<int> dist(n,INT_MAX);
    q.push(src);
    dist[src] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto a:adj[node]){
            if(dist[node]+1 < dist[a]){
                dist[a] = dist[node]+1;
                q.push(a);
            }
        }
    }
    cout<<endl<<"Distance of Every Node from Source Node: "<<endl;
    for(int i=0;i<n;i++) cout<<src<<"->"<<i<<" = "<<dist[i]<<endl;
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
    bfs_path(n,adj,0);
    return 0;
}

// INPUT
// 9 11
// 0 1
// 0 3
// 1 2
// 1 3
// 2 6
// 3 4
// 4 5
// 5 6
// 6 7
// 6 8
// 7 8