// Simple trick to do Topological sort is to fist make recursive dfs and at end of every recursion call store
// the node into stack... that stack will contain the nodes in reverse order of topological order
//Instead of stack we can also use vector just reverse the result before printing the output

#include<bits/stdc++.h>
using namespace std;

void Topological(int i,vector<int> &vis,stack<int> &st,vector<int> adj[]){
    vis[i] = 1;
    for(int a:adj[i]){
        if(!vis[a]){
            Topological(a,vis,st,adj);
        }
    }

    st.push(i);
}
int main(){
    // Input Nodes and Edges 
    int n,m;
    cin>>n>>m;
    // Declaring a Graph
    vector<int> adj[n]; //(0 based indexing of nodes)
    // Input the edges (Directed Graph)
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int> vis(n,0);
    stack<int> st;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            Topological(i,vis,st,adj);
        }
    }
    cout<<"RESULT: ";
    vector<int> res;
    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }
    for(int i:res) cout<<i<<" ";
    return 0;
}

// Input Graph (Directed)

// 6 6
// 5 0
// 5 2
// 4 0
// 4 1
// 2 3
// 3 1