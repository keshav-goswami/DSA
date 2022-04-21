#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
int main(){
    int N,E;
    // enter weighted graph
    cout<<"Enter N and E: ";
    cin>>N>>E;
    vector<pair<int,pair<int,int>>> vp,res;
    cout<<"Enter values: ";
    for(int i=0;i<E;i++){
        int w,u,v;
        cin>>w>>u>>v;
        vp.push_back(make_pair(w,make_pair(u,v)));
    }
    cout<<"Enter Source: ";
    int src;
    cin>>src;
    vector<int> dist(N,INF);
    dist[src] = 0;
    for(int i=0;i<N-1;i++){
        for(int j=0;j<N;j++){
            int w = vp[j].first;
            int u = vp[j].second.first;
            int v = vp[j].second.second;
            dist[v] = min(dist[v],w + dist[u]);
        }
    }

    // checking negative cycles
    for(int i=0;i<N;i++){
        int w = vp[i].first;
        int u = vp[i].second.first;
        int v = vp[i].second.second;
        if(dist[v]>dist[u]+w){
            cout<<"Negative Cycle Exist";
            break;
        }
    }
    for(auto i:dist) cout<<i<<" ";
    return 0;
}

// 3 1 2
// 2 1 3
// 5 2 4
// 6 2 5
// 11 3 7
// 8 3 6