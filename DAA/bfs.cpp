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
    queue<int> q;
    q.push(S); //source node pushed
    int st[N] = {0};
    st[S] = -1;
    signal[S] = 1;
    while(!q.empty())
    {
        int f = q.front();
        q.pop();
        signal[f] = 2;
        // cout<<f<<endl;
        vector<int> :: iterator it;
        if(f == D) break;
        for(it = gf[f].begin();it!= gf[f].end();it++){
            if(signal[*it]==0){
                q.push(*it);
                if(st[*it] == 0) st[*it] = f; //Important
                else if(st[*it]>f) st[*it] = f; 
                cout<<*it<<"->"<<st[*it]<<endl;
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
    cout<<"Shortest Path: ";
    for(auto i:path) cout<<i<<" ";
    cout<<"Shortest Length: "<<path.size();
    return 0;
}