// Breadth First Search
#include<bits/stdc++.h>
using namespace std;

vector<int> BFS(int N,vector<int> adj[]){
    vector<int> bfs;
    vector<bool> visited(N+1,0);
    for(int i=1;i<=N;i++){
        if(!visited[i]){
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                bfs.push_back(node);
                for(auto a:adj[node]){
                    if(!visited[a]){
                        q.push(a);
                        visited[a] = true;
                    }
                }
            }
        }
    }
    return bfs;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ans = BFS(n,adj);
    cout<<"BFS PATH: "<<endl;
    for(auto i:ans) cout<<i<<" ";
    return 0;
}
// Time Compexity: O(N+E)
// Space Compexity: O(N+E)

// INPUT 
// 7 6
// 1 2
// 2 3
// 2 7
// 3 5
// 4 6
// 5 7