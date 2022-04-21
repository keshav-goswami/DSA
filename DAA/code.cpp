#include<bits/stdc++.h>
using namespace std;

void find_erase(vector<int> &v,int e){
    auto it1 = find(v.begin(), v.end(),e);
    int index1 = it1 - v.begin();
    v.erase(v.begin()+index1);
}
int main(){
    int N;
    cin>>N;
    vector<int> v,R,S;
    for(int i=0;i<N;i++){
        int u;
        cin>>u;
        v.push_back(u);
        R.push_back(u);
        S.push_back(u);
    }
    sort(R.begin(),R.end(),greater<int>());
    sort(S.begin(),S.end());
    int c = 0;
    while(v.size()!=1){
        find_erase(v,R[c]);
        find_erase(R,R[c]);
        find_erase(S,R[c]);
        
        if(v.size() == 1) break;
        find_erase(v,S[c]);
        find_erase(R,S[c]);
        find_erase(S,S[c]);
        c++;
    }
    cout<<v[0]<<endl;
    return 0;
}