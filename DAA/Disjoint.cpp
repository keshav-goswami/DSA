#include<bits/stdc++.h>
using namespace std;
int find(int u,vector<int> &parent){
    if(parent[u]<0) return u;
    else return find(parent[u],parent);
}
void unionbyW(int u,int v,vector<int> &parent){
    int pu = find(u,parent);
    int pv = find(v,parent);
    if(pu!=pv){
        if(parent[pu]<parent[pv]){
            parent[pu]+=parent[pv];
            parent[pv] = pu;
        }
        else{
            parent[pv]+=parent[pu];
            parent[pu] = pv;
        }
    }
}
int main(){
    int N = 1e5+1;
    int nodes,edges;
    cout<<"Enter N and E: ";
    cin>>nodes>>edges;
    vector<int> gp[N];
    cout<<"Enter values: ";
    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        gp[u].push_back(v);
    }
    vector<int> parent(nodes,-1);
    unionbyW(2,3,parent);
    for(auto i:parent) cout<<i<<" ";
    return 0;
}