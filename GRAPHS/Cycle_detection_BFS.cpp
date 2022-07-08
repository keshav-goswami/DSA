// Detect a cycle in Graph using BFS
#include<bits/stdc++.h>
using namespace std;

bool cycleBFS(int node,vector<int> &visited,vector<int> adj[]){
    queue<pair<int,int>> q;
    q.push({node,-1});
    visited[node] = 1;
    while(!q.empty()){
        int node = q.front().first;
        int prev = q.front().second;
        q.pop();
        for(auto a:adj[node]){
            if(!visited[a]){
                q.push({a,node});
                visited[a] = 1;
            }
            else if(prev != a){
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
    vector<int> vis(n+1,0);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(cycleBFS(i,vis,adj)){
                cout<<"CYCLE EXISTS"<<endl;
                return 0;
            }
        }
    }
    cout<<"CYCLE DOESN'T EXIST"<<endl;
    return 0;
}
// INPUT
// 7 6
// 1 2
// 2 4
// 2 7
// 3 5
// 4 6
// 6 7


