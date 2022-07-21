// Undirected Graph
// Dijksta's Algorith....
// Use a Priority queue and insert distance and node in it and keep on iterating on these nodes with shortest distance using queue(same as bfs).

#include <bits/stdc++.h>
using namespace std;
void Dijkstra(int n, vector<pair<int, int>> adj[], int src)
{
    vector<int> dis(n + 1, INT_MAX);
    priority_queue<pair<int, int>> pq;
    pq.push({0, src});
    dis[src] = 0;
    while (!pq.empty()){
        int node = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        // cout<<node<<" "<<d<<endl;
        for (auto a : adj[node]){
            if ((d + a.second) < dis[a.first]){
                dis[a.first] = d + a.second;
                pq.push({dis[a.first], a.first});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << src << " -> " << i <<" = "<<dis[i]<< endl;
    }
}
int main()
{
    // Input Nodes and Edges 
    int n,m;
    cin>>n>>m;
    // Declaring a Graph
    vector<pair<int,int>> adj[n+1];
    // Input the edges (Directed Graph)
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    cout << "Enter the Source: ";
    int src;
    cin >> src;
    Dijkstra(n, adj, src);
    return 0;
}

// INPUT UNDIRECTED
// 5 6
// 1 2 2
// 1 4 1
// 2 5 5
// 2 3 4
// 3 4 3
// 3 5 1
