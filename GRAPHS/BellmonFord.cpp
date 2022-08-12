// TC = O(N-1)*O(E)

#include<bits/stdc++.h>
using namespace std;
struct node {
    int u;
    int v;
    int wt; 
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    // Declaring a Graph
    vector<node> adj;
    // Input the edges (Directed Graph)
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj.push_back(node(u,v,w));
    }
    int src=0;
    int inf = 10000000; 
    vector<int> dist(n, inf); 
    dist[src] = 0; 
    for(int i = 1;i<=n-1;i++) {
        for(auto it: adj) {
            if(dist[it.u] + it.wt < dist[it.v]) {
                dist[it.v] = dist[it.u] + it.wt; 
            }
        }
    }

    int fl = 0; 
    for(auto it: adj) {
        if(dist[it.u] + it.wt < dist[it.v]) {
            cout << -1; 
            fl = 1; 
            break; 
        }
    }
    
    if(!fl) {
        for(int i = 0;i<n;i++) {
            cout << dist[i]<<" ";
        }
    }
    return 0;
}

// INPUT
// 6 7
// 0 1 5
// 1 2 -2
// 1 5 -3
// 2 4 3
// 3 2 6
// 3 4 -2
// 5 3 1