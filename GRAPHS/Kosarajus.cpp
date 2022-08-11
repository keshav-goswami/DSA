
#include<bits/stdc++.h>
using namespace std;

// Strongly Connected Components

// Steps 
// 1) Find The topological sort
// 2) Transpose the graph
// 3) Perform DFS with topo order in transposed graph


void toposort(int node,vector<int> &vis,stack<int> &st,vector<int> adj[]){
    vis[node] = 1;
    for(auto i:adj[node]){
        if(!vis[i]) toposort(i,vis,st,adj);
    }
    st.push(node);
}

void DFS(int node,vector<int> &vis,vector<int> adj[],vector<vector<int>> &ans){
    vis[node] = 1;
    cout<<node<<" ";
    for(auto i:adj[node]){
        if(!vis[i]) {
            DFS(i,vis,adj,ans);
        }
    }
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
    stack<int> st;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            toposort(i,vis,st,adj);
        }
    }

    // Print toposort
    // while(!st.empty()){
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }

    vector<int> transpose[n+1];
    for(int i=1;i<=n;i++){
        for(auto a:adj[i]){
            transpose[a].push_back(i);
        }
    }
    for(int i=0;i<=n;i++) vis[i] = 0;
    vector<vector<int>> ans;
    cout<<"\n\nStrongle Connected Components: "<<endl;
    while(!st.empty()){
        int i = st.top();
        st.pop();
        if(!vis[i]){
            DFS(i,vis,transpose,ans);
            cout<<endl;
        }
    }
    // for(auto i:ans){
    //     for(auto j:i) cout<<j<<" ";
    // }
    return 0;
}