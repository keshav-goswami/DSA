#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+1;
vector<bool> visited(N,0);
vector<int> gf[N];

void dfs(int node){
    // inorder
    // cout<<node<<" ";
    visited[node] = true;
    for(auto i=gf[node].begin();i!=gf[node].end();i++){
        if(!visited[*i]) dfs(*i);
    }
    // post order
    // cout<<node<<" ";
}
int main(){
    int v,e,S,x,y;
    cout<<"Enter nodes and vertices: ";
    cin>>v>>e;
    cout<<"Enter Souce Node: ";
    cin>>S;
    cout<<"Enter graph nodes: ";
    set<int> st;
    while(e--){
        cin>>x>>y;
        st.insert(x); 
        st.insert(y);
        gf[x].push_back(y);
        gf[y].push_back(x);
    }

    // display graph 

    // cout<<endl;
    // for(auto i:st){ 
    //     cout<<i<<": ";
    //     for(int j=0;j<gf[i].size();j++){
    //         cout<<gf[i][j]<<" ";
    //     }
    //     cout<<endl;
    // } 
    // return 0;

// BFS

    // queue<int> q;
    // q.push(S);
    // visited[S] = true;
    // while(!q.empty()){
    //     int n = q.front();
    //     cout<<n<<" "; 
    //     q.pop();
    //     for(auto i = gf[n].begin();i!=gf[n].end();i++){
    //         if(!visited[*i]){
    //             visited[*i] = true;
    //             q.push(*i);
    //         }
    //     }
    // }

// DFS using stack
    stack<int> stk;
    stk.push(S); //source node pushed
    while(!stk.empty())
    {
        int f = stk.top();
        stk.pop();
        if(!visited[f]){
                visited[f] = 1;
                cout<<f<<" ";
        }
        for(auto it = gf[f].begin();it!= gf[f].end();it++){
            if(!visited[*it]){
                stk.push(*it);
            }
        }
    }

    // Recursive way
    // dfs(S);

}
// input graph 
// 1 4
// 1 2
// 2 5
// 4 5
// 2 3
// 5 6
