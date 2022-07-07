// DFS ALGORITHM
#include <bits/stdc++.h>
using namespace std;

void DFS_recurr(int node,vector<bool> &vis,vector<int> adj[],vector<int> &dps){
    dps.push_back(node);
    vis[node] = true;
    for(auto a:adj[node]){
        if(!vis[a]){
            DFS_recurr(a,vis,adj,dps);
        }
    }
}

// vector<int> DFS_stack(int N, vector<int> adj[])
// {
//     vector<int> dfs;
//     vector<bool> visited(N+1,0);
//     for (int i = 1; i <= N; i++)
//     {
//         if (!visited[i])
//         {
//             stack<int> st;
//             st.push(i);
//             visited[i] = true;
//             while (!st.empty())
//             {
//                 int node = st.top();
//                 st.pop();
//                 dfs.push_back(node);
//                 for (auto a : adj[node])
//                 {
//                     if(!visited[a]){
//                         st.push(a);
//                         visited[a] = true;
//                     }
//                 }
//             }
//         }
//     }
//     return dfs;
// }
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> res;
    vector<bool> vis(n+1,0);
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<"DFS RECURSION: ";
    for(int i=1;i<=n;i++){
        if(!vis[i]) DFS_recurr(i,vis,adj,res);
    }
    for(auto i:res) cout<<i<<" ";
//     vector<int> ans = DFS_stack(n,adj);
//     cout<<endl<<"DFS PATH: "<<endl;
//     for(auto i:ans) cout<<i<<" ";
//     return 0;
}
// Time Compexity: O(N+E)
// Space Compexity: O(N+E)

// INPUT 
// 7 6
// 1 2
// 2 4
// 2 7
// 3 5
// 4 6
// 6 7