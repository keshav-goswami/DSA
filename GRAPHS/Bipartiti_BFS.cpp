#include<bits/stdc++.h>
using namespace std;

bool Bfs_Bapartite(int n,vector<int> &color,vector<int> adj[]){
    queue<int> q;
    q.push(n);
    color[n] = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto a:adj[node]){
            if(color[a] == -1){
                q.push(a);
                color[a] = 1 - color[node];
            }
            else if(color[a] == color[node]){
                return true;
            }
        }
    }
    return false;
    
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    vector<int> color(n+1,-1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(color[i]==-1){
            if(Bfs_Bapartite(i,color,adj)){
                cout<<"Not a Bapartite";
                return 0;
            }
        }
    }
    cout<<"It is a Bapartite";
    return 0;
}

// Not a Bapartite input
// 8 8
// 1 2
// 2 3
// 2 8
// 3 4
// 4 5
// 5 8
// 5 6
// 6 7

// A Bapartite input
// 8 8
// 1 2
// 2 3
// 2 8
// 3 4
// 4 6
// 5 8
// 5 6
// 6 7
