#include<bits/stdc++.h>
using namespace std;
void topoutils(vector<int> gp[],bool visited[],stack<int> &st,int i){
    visited[i] = true;
    for(int j=0;j<gp[j].size();j++){
        if(!visited[gp[i][j]]){
            topoutils(gp,visited,st,gp[i][j]);
        }
    }
    st.push(i);
}
int main(){
    int N = 1e5+1;
    int nodes,edges;
    cout<<"Enter N and E: ";
    cin>>nodes>>edges;
    bool visited[nodes];
    vector<int> gp[N];
    cout<<"Enter values: ";
    for(int i=0;i<edges;i++)
    {
        int u,v;
        cin>>u>>v;
        gp[u].push_back(v);
    }
    stack<int> st;
    for(int i=0;i<nodes;i++) visited[i] = false;
    for(int i=0;i<nodes;i++){
        if(!visited[i]){
            topoutils(gp,visited,st,i);
        }
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}