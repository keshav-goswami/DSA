#include<bits/stdc++.h>
using namespace std;
bool topo_bfs(vector<int> adj[],int n){
    vector<int> indegree(n+1,0);
    queue<int> q;
    for(int i=1;i<=n;i++){
        for(auto a:adj[i]) indegree[a]++;
    }
    for(int i=1;i<=n;i++){
        if(!indegree[i]) q.push(i);
    }
    int c = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        c++;
        for(auto a:adj[node]){
            indegree[a]--;
            if(indegree[a] == 0) q.push(a);
        }
    }
    if(c == n) return true;
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
    if(topo_bfs(adj,n)) cout<<"It's is not cyclic";
    else cout<<"It is cyclic";
    return 0;
}