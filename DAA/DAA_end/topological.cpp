#include<bits/stdc++.h>
using namespace std;
void topological_utils(stack<int> &st,int i,vector<int> gp[],bool visited[]){
    visited[i] = true;
    for(int j=0;j<gp[i].size();j++){
        if(!visited[gp[i][j]]) topological_utils(st,gp[i][j],gp,visited);
    }
    st.push(i);
}
void topological(vector<int> gp[],int N){
    stack<int> st;
    bool visited[N];
    for(int i=0;i<N;i++) visited[i] = false;
    for(int i=0;i<N;i++){
        if(!visited[i]) topological_utils(st,i,gp,visited);
    }
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
}

int main(){
    int N,E;
    cin>>N>>E;
    vector<int> gp[N];
    for(int i=0;i<E;i++){
        int s,d;
        cin>>s>>d;
        gp[s].push_back(d);
    }
    topological(gp,N);
    return 0;
}