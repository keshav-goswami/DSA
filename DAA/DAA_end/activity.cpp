#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> vp;
    for(int i=0;i<n;i++){
        int e,s;
        cin>>s>>e;
        vp.push_back(make_pair(e,s));
    }
    sort(vp.begin(),vp.end());
    // Find no of processors
    int count = 0;
    int curr = -1;
    while(!vp.empty()){
        curr = -1;
        for(int i=0;i<vp.size();i++){
            if(vp[i].second > curr){
                curr = vp[i].first;
                vp.erase(i+vp.begin());
                i--;
            }
        }
        count++;
    }
    cout<<count;
    return 0;
}