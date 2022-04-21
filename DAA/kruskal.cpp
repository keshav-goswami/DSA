#include<bits/stdc++.h>
using namespace std;
typedef vector<pair<int,pair<int,int>>> viii;

int findd(int u,vector<int> &parent){
    if(parent[u]<0) return u;
    else return findd(parent[u],parent);
}
void unionbyW(int u,int v,vector<int> &parent){

    if(u!=v){
        if(parent[u]<parent[v]){
            parent[u]+=parent[v];
            parent[v] = u;
        }
        else{
            parent[v]+=parent[u];
            parent[u] = v;
        }
    }
}
int main(){
    int N = 1e5+1;
    int nodes,edges;
    // enter weighted graph
    cout<<"Enter N and E: ";
    cin>>nodes>>edges;
    viii gp,res;
    cout<<"Enter values: ";
    for(int i=0;i<edges;i++){
        int w,u,v;
        cin>>w>>u>>v;
        gp.push_back(make_pair(w,make_pair(u,v)));
    }
    //  Kruskal
    int min_cost=0;
    int c=0;
    vector<int> parent(nodes,-1);
    sort(gp.begin(),gp.end());

    for(int i=0;i<edges;i++){
        int s = gp[i].second.first;
        int d = gp[i].second.second;
        if(findd(s,parent)!=findd(d,parent)){
            min_cost+=gp[i].first;
            res.push_back(gp[i]);
            unionbyW(findd(s,parent),findd(d,parent),parent);
            c++;
        }
    }

    cout<<min_cost;
    int wsum = 0;
    for(int i=0;i<c;i++){
        int w = res[i].first;
        cout<<res[i].second.first<<" "<<res[i].second.second;
        wsum+=w;
    }
    cout<<"Weight :"<<wsum;
    return 0;
}