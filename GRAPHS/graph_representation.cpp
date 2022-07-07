// Both Representations of Graph Adjacency Matrix and Adjacency List
#include<bits/stdc++.h>
using namespace std;

// Adjacency List
int main(){
    int n,m;
    cin>>n>>m;

    vector<pair<int,int>> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    for(int i=1;i<=n;i++){
        for(auto a:adj[i]){
            cout<<i<<"->"<<a.first<<" "<<a.second<<endl;
        }
    }
    return 0;
}

// Adjacency Matrix
// int main(){
//     int n,m;
//     cin>>n>>m;

//     int adj[n+1][n+1];
//     memset(adj,0,sizeof(adj));
//     for(int i=0;i<m;i++){
//         int u,v;
//         cin>>u>>v;
//         adj[u][v] = 1;
//         adj[v][u] = 1;
//     }
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             cout<<adj[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }
// Adjacency List
// INPUT Graph
// 5 7
// 1 2 5
// 1 3 2
// 1 5 4
// 2 4 10
// 2 3 6
// 3 4 10
// 3 5 6

// Adjacency Matrix
// 5 7
// 1 2 
// 1 3 
// 1 5
// 2 4
// 2 3
// 3 4
// 3 5