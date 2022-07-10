// The Intiution Behind this is to use Kahn's algo of topological sort. As we kknow we can only find topological order for Directed Acyclic graphs So we can use this to find whether a graph is cyclic or not...
// We will just count the elements in resultant topological order if it is equal to number of nodes thn we got the topological sort ,Hence it is acyclic otherwise cyclic.....

#include<bits/stdc++.h>
using namespace std;

bool Topological_Bfs(int n,vector<int> adj[]){
    vector<int> indegree(n+1,0);
    queue<int> q;

    for(int i=1;i<=n;i++){
        for(auto a:adj[i]){
            indegree[a]++;
        }
    }
    for(int i=1;i<=n;i++){
        if(!indegree[i]) q.push(i);
    }
    int cnt = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cnt++;
        for(auto a:adj[node]){
            indegree[a]--;
            if(!indegree[a]) q.push(a);
        }
    }
    if(cnt == n) return true;
    else return false;
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
    if(Topological_Bfs(n,adj)) cout<<"Cycle Doesn't Exists";
    else cout<<"Cycle Exists";
    return 0;
}


// Input Cycle Exists

// 9 10
// 1 2
// 2 3
// 3 4
// 4 5
// 3 6
// 6 5
// 7 2
// 7 8
// 8 9
// 9 7


// Input Cycle Doesn't Exists

// 9 10
// 1 2
// 2 3
// 3 4
// 4 5
// 3 6
// 6 5
// 7 2
// 7 8
// 8 9
// 7 9