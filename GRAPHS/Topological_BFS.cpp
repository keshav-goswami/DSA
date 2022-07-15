// (Kahn's Algorithm) // It is different from DFS approach, here we will use Indegree and visited array and will push only those elements (nodes) in queue with indegree == 0

// INDEGREE : MEANS NUMBER OF PARENTS A NODE HAVE If Indegree == 0 that means No existing Parents pf that node....
// So , here we are just taking nodes with zero indegree and after popping them from queue, we make sure that we reduce the indegree of its childs.....

// Key point : unlike dfs topo we won't pass nodes in loop from main, just call it one time.
#include<bits/stdc++.h>
using namespace std;
vector<int> Topological(int N,vector<int> adj[]){
    vector<int> topo;
    queue<int> q;
    vector<int> indegree(N,0);
    for(int i=0;i<N;i++){
        for(auto a:adj[i]){
            indegree[a]++;
        }
    }
    for(int i=0;i<N;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto a:adj[node]){
            indegree[a]--;
            if(indegree[a] == 0) q.push(a);
        }
    }
    return topo;
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
    vector<int> ans = Topological(n,adj);
    cout<<"RESULT: ";
    for(int i:ans){
        cout<<i<<" ";
    }
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