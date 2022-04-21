#include<bits/stdc++.h>
using namespace std;
typedef vector<pair<int,pair<int,int>>> viii;

int find(int e,int *parent){
    if(parent[e]<0) return e;
    else return find(parent[e],parent);
}

void UnionByWeight(int u,int v,int *parent){
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
        // cout<<u<<"->"<<v<<endl; //// edges that are not cyclic
    }
}
void kruskal(viii gp,int N,viii &res){
    int parent[N];
    for(int i=0;i<N;i++) parent[i] = -1;
    for(int i=0;i<N;i++){
        int w = gp[i].first;
        int s = gp[i].second.first;
        int d = gp[i].second.second;
        if(find(s,parent)!=find(d,parent)){
            res.push_back(gp[i]);
            UnionByWeight(s,d,parent);
        }
    }
}
int main(){
    int e,n;
    cin>>e>>n;
    viii gp;
    for(int i=0;i<e;i++){
        int w,s,d;
        cin>>s>>d>>w;
        gp.push_back(make_pair(w,make_pair(s,d)));
    }
    sort(gp.begin(),gp.begin());
    viii res;
    kruskal(gp,n,res);
    int sum = 0;
    cout<<"RESULT: "<<endl;
    for(int i=0;i<n;i++){
        cout<<gp[i].first<<" "<<gp[i].second.first<<" "<<gp[i].second.second<<endl;
        sum = sum+gp[i].first;
    }
    cout<<sum;
    return 0;
}

// INPUT
// 9 6
// 0 1 1
// 1 5 2
// 0 5 3
// 1 2 4
// 1 4 5
// 5 4 6
// 2 4 7
// 2 3 8
// 3 4 9