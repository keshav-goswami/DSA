#include<bits/stdc++.h>
using namespace std;
// making function union and find parent
// to decrease time complexity from log(n) to const (4alpha) i will be using Path Compression
int findParent(int node,vector<int> &parent){
    if(node == parent[node]) return node;
    return parent[node] = findParent(parent[node],parent);
}

void Union(int u,int v,vector<int> &rank,vector<int> &parent){
    // if(findParent(u,parent)!=findParent(v,parent))
    u = findParent(u,parent);
    v = findParent(v,parent);
    if(rank[u]<rank[v]){
        parent[u] = v;
    }
    else if(rank[v]<rank[u]){
        parent[v] = u;
    }else{
        parent[u] = v;
        rank[v]++;
    }
}

int main(){
    // Input Nodes and Edges 
    int n,m;
    cin>>n>>m;
    // Declaring a Graph
    vector<pair<int,int>> adj[n+1];
    vector<pair<int,pair<int,int>>> vp;
    // Input the edges (UnDirected Graph)
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        pair<int,int> p = {u,v};
        vp.push_back({w,p});
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    // Disjoint
    // 1) Setting values 
    vector<int> parent(n+1);
    vector<int> rank(n+1);
    for(int i=1;i<=n;i++){
        parent[i] = i;
        rank[i] = 0;
    }
    // 2) To make function union and find parent

    sort(vp.begin(),vp.end());

    // Minimum spanning tree using Kruskal
    int cnt=0;
    vector<pair<int,int>> MST;
    for(auto i:vp){
        int w = i.first;
        int u = i.second.first;
        int v = i.second.second;
        if(findParent(u,parent)!=findParent(v,parent)){
            // cout<<u<<" "<<v<<" "<<w<<endl;
            Union(u,v,rank,parent);
            cnt+=w;
            MST.push_back({u,v});
        }
    }
    // for(int i=0;i<n;i++) cout<<findParent(i,parent)<<" ";
    cout<<"\nMINIMUM SPANNING TREE WEIGHT: "<<cnt<<endl;
    cout<<"THE MST EDGES: "<<endl;
    for(auto a:MST) cout<<a.first<<" "<<a.second<<endl;
    return 0;
}

// INPUT
// 6 9
// 1 4 1
// 1 2 2
// 1 5 4
// 2 4 3
// 2 3 3
// 2 6 7
// 3 4 5
// 3 6 8
// 4 5 9