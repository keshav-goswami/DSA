// Shortest Distance in DAG using DFS (Weighted Graph)

#include<bits/stdc++.h>
using namespace std;
void dfs_topo(int i,vector<int> &vis,vector<pair<int,int>> adj[],stack<int> &st){
    vis[i] = 1;
    for(auto a:adj[i]){
        if(!vis[a.first]){
            dfs_topo(a.first,vis,adj,st);
        }
    }
    st.push(i);
}

void Shortest_path(int i,vector<int> &dist,vector<pair<int,int>> adj[],int src,int n){
    dist[src] = 0;
    if(dist[i]!= INT_MAX){
        for(auto a:adj[i]){
            if(dist[i]+a.second < dist[a.first]){
                dist[a.first] = dist[i]+a.second;
            }
        }
    }
}

int main(){
    // Input Nodes and Edges 
    int n,m;
    cin>>n>>m;
    // Declaring a Graph
    vector<pair<int,int>> adj[n];
    // Input the edges (Directed Graph)
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
    }
    vector<int> vis(n,0);
    stack<int> st;
    for(int I=0;I<n;I++){
        if(!vis[I]){
            dfs_topo(I,vis,adj,st);
        }
    }

    // vector<int> topo;
    // while(!st.empty())
    // {
    //     cout<<st.top()<<" ";
    //     topo.push_back(st.top());
    //     st.pop();
    // }
    vector<int> dist(n,INT_MAX);
    while(!st.empty()){
        Shortest_path(st.top(),dist,adj,0,n);
        st.pop();
    }
    cout<<endl<<"RESULT: "<<endl;
    for(int i=0;i<n;i++) cout<<0<<"->"<<i<<" = "<<dist[i]<<endl;
    return 0;
}

// INPUT (Directed Graph)
// 6 7
// 0 1 2
// 0 4 1
// 1 2 3
// 2 3 6
// 4 2 2
// 4 5 4
// 5 3 1
