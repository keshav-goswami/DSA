#include<bits/stdc++.h>
using namespace std;
int find(int e,int *parent){
    if(parent[e]<0) return e;
    else return find(parent[e],parent);
}
void UnionByWeight(int u,int v,int *parent){
    // collapsing
    // if(parent[u]!=-1) parent[u] = find(u,parent); 
    // if(parent[v]!=-1) parent[v] = find(v,parent);   //not correct

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
        cout<<u<<"->"<<v<<endl; // edges that are not cyclic
    }
}
int main(){
    int S[] = {1,3,5,7,2,2,1,6,5};
    int D[] = {2,4,6,8,4,5,3,8,7};
    // 9-E 8-N
    int N = 8;
    int E = 9;
    vector<int> gp[N];
    for(int i=0;i<N;i++){
        gp[S[i]].push_back(D[i]);
        gp[D[i]].push_back(S[i]);
    }
    int parent[N];
    for(int i=0;i<N;i++) parent[i] = -1;
    for(int i=0;i<N;i++){
        UnionByWeight(S[i],D[i],parent);
    }
    return 0;
}