#include<bits/stdc++.h>
using namespace std;

int main(){
    int st[] = {7,5,8,5,0,3,1};
    int end[] = {9,9,9,7,6,4,2};
    int n;
    cin>>n;
    vector<pair<int,int>> vp;
    for(int i=0;i<n;i++){
        int e,s;
        cin>>e>>s;
        vp.push_back(make_pair(e,s));
    }
    sort(vp.begin(),vp.end());
    int curr = -1;
    int count = 0;
    for(int i=0;i<vp.size();i++){
        if(vp[i].second>curr){
            count++;
            curr = vp[i].first;
        }
    }
    cout<<count;
    return 0;
}