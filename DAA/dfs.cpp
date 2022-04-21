#include<bits/stdc++.h>
using namespace std;
int main(){
    int nodes,edges,u,v,S,D;
    int N = 1e5+1;
    vector<int> gf[N];
    int signal[N] = {0};
    cout<<"Enter Nodes and Edges: ";
    cin>>nodes>>edges;
    cout<<"Enter Source and destination Node: ";
    cin>>S>>D;
    while(edges--){
        cin>>u>>v;// Undirected graph
        gf[u].push_back(v);
        gf[v].push_back(u);
    }
    stack<int> stk;
    stk.push(S); //source node pushed
    int st[N];
    st[S] = -1;
    while(!stk.empty())
    {
        int f = stk.top();
        stk.pop();
        signal[f] = 1;
        vector<int> :: iterator it;
        if(f == D) break;
        for(it = gf[f].begin();it!= gf[f].end();it++){
            if(signal[*it]==0){
                stk.push(*it);
                st[*it] = f;
            }
        }
    }
    int node = D;
    vector<int> path;
    path.push_back(D);
    while(st[node]!=-1){
        path.push_back(st[node]);
        node = st[node]; 
    }
    reverse(path.begin(),path.end());
    cout<<"Path: ";
    for(auto i:path) cout<<i<<" ";
    cout<<"Length: "<<path.size();
    return 0;
}