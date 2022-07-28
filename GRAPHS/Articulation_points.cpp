// Pre-requisites BRIDGES IN GRAPH

#include<bits/stdc++.h>
using namespace std;
map<int,bool> mp;
void dfs(int node,int parent,vector<int> adj[],vector<int> &vis,vector<int> &tin,vector<int> &lw,int &timer){
    vis[node] = 1;
    lw[node] = tin[node] = timer++;
    int child = 0;
    for(auto a:adj[node]){
        // adjacent node should not be parent of current node
        if(a == parent) continue;
        // counting individual childs for parent node
        if(!vis[a]){
            dfs(a,node,adj,vis,tin,lw,timer);
            lw[node] = min(lw[node],lw[a]);
            if(lw[a] >= tin[node] && parent!=-1) mp[node] = 1; 
            child++;
        }else{
            lw[node] = min(lw[node],tin[a]);
            // cout<<lw[a]<<" "<<tin[node]<<endl;
        }
        
    }
    if(child>1 && parent == -1) mp[node] = 1;
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
    vector<int> vis(n,0);
    vector<int> tin(n,-1);
    vector<int> lw(n,-1);
    int timer = 0;
    for(int i=0;i<n;i++) mp[i] = false;
    for(int i=0;i<n;i++){
        if(!vis[i]) dfs(i,-1,adj,vis,tin,lw,timer);
    }
    cout<<"ARTICULATION POINTS: \n";
    for(auto i:mp){
        if(i.second) cout<<i.first<<endl;
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