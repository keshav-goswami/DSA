#include<bits/stdc++.h>
using namespace std;

int main(){
    // Input Nodes and Edges 
    int n,m;
    cin>>n>>m;
    // Declaring a Graph
    vector<pair<int,int>> adj[n+1];
    // Input the edges (Directed Graph)
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    // Prims Algorithm (BRUTE FORCE O(N^2))
    // vector<int> dis(n+1,INT_MAX);
    // vector<int> parent(n+1,-1);
    // vector<bool> MST(n+1,false);
    // // Marking key and MST for source node
    // dis[1] = 0;
    // // Will Run loop for N-1 edges as we know there are N-1 edges in MST
    // for(int i=0;i<n-1;i++){
    //     int mini = INT_MAX,node;
    //     // Finding minimum distance node and its minimum distance value
    //     for(int j=1;j<=n;j++){
    //         if(dis[j]<mini && !MST[j]){
    //             mini = dis[j];
    //             node = j;
    //         }
    //     }
    //     MST[node] = true;
    //     // Accessing the adjacent nodes and marking the MST,dis and parent for them
    //     for(auto a:adj[node]){
    //         int n = a.first;
    //         int weight = a.second;
    //         if(!MST[n] && dis[n]>weight){
    //             dis[n] = weight;
    //             parent[n] = node;
    //         }
    //     }
    // }

    // Prims Algorithm (OPTIMIZED O(NLogN) -> using priority queue)
    // Min heap (priority queue)
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq; //{dis,node}
    vector<int> dis(n+1,INT_MAX);
    vector<int> parent(n+1,-1);
    vector<bool> MST(n+1,false);
    // Marking key and MST for source node
    pq.push({0,1});
    dis[1] = 0;
    // Will Run loop for N-1 edges as we know there are N-1 edges in MST
    while(!pq.empty()){
        // Finding minimum distance node and its minimum distance value
        int node = pq.top().second;
        cout<<pq.top().first<<" "<<node<<endl;
        pq.pop();
        if(MST[node]) continue;
        // cout<<pq.top().first<<endl;
        MST[node] = true;
        // Accessing the adjacent nodes and marking the MST,dis and parent for them
        for(auto a:adj[node]){
            int n = a.first;
            int weight = a.second;
            if(!MST[n] && dis[n]>weight){
                dis[n] = weight;
                pq.push({dis[n],n});
                parent[n] = node;
            }
        }
    }
    int sum = 0;
    for(int a:dis) if(a!=INT_MAX) sum+=a;
    cout<<"Minimum Spanning Tree Weight: "<<sum<<endl;
    cout<<"MST Edges:"<<endl;
    for(int i=1;i<=n;i++){
        cout<<i<<"->"<<parent[i]<<endl;
    }
    return 0;
}

// INPUT
// 5 6
// 1 2 2
// 1 4 1
// 2 5 5
// 2 3 4
// 3 4 3
// 3 5 1