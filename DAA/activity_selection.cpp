#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<pair<int,int>> vp;
    int N;
    cin>>N;
    int s,e;
    for(int i=0;i<N;i++){
        cin>>s>>e;
        vp.push_back(make_pair(e,s));
    } 
    sort(vp.begin(),vp.end());

    int count = 0;
    int curr = -1;
    int ind;
    while(vp.size()!=0){
        curr = -1;
        for(int i=0;i<vp.size();i++){
            if(vp[i].second>curr){
                curr = vp[i].first;
                vp.erase(vp.begin()+i);
                i--;
            }
        }
        count++;
    }
    cout<<count<<endl;
    return 0;
}