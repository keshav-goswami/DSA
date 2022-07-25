#include<bits/stdc++.h>
using namespace std;
int parent[100000];
int ranks[100000];

void set_values(){
    for(int i=0;i<100000;i++){
        parent[i] = i;
        ranks[i] = 0;
    }
}
// To do Path Compression just add parent[node] in front of return
int findParent(int node){
    if(node == parent[node]) return node;
    return parent[node] = findParent(parent[node]);
}

void Union(int u,int v){
    u = findParent(u);
    v = findParent(v);
    if(ranks[u] < ranks[v]){
        parent[u] = v;
    }
    else if(ranks[v] < ranks[u]){
        parent[v] = u;
    }
    else{
        parent[u] = v;
        ranks[u]++;
    }
}

int main(){
    set_values(); 
    Union(0,1);   
    Union(1,2);
    Union(2,3);
    Union(4,5);
    Union(6,7);
    Union(5,6);
    cout<<"PARENT ARRAY: ";
    for(int i=0;i<8;i++) cout<<findParent(i)<<" ";
    cout<<"\nRANK ARRAY: ";
    for(int i=0;i<8;i++) cout<<ranks[i]<<" ";
    if(findParent(1) != findParent(7)){
        cout<<"\nDifferent Components";
    }else{
        cout<<"\nConnected Commponents";
    }
    return 0;
}