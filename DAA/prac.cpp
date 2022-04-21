#include<bits/stdc++.h>
using namespace std;

int main(){
    int st[] = {1,3,0,5,8,5,7};
    int ed[] = {2,4,6,7,9,9,9};
    vector<pair<int,int>> vp;
    for(int i=0;i<sizeof(st)/sizeof(st[0]);i++){
        vp.push_back(make_pair(ed[i],st[i]));
    }
    sort(vp.begin(),vp.end());
    int curr = 0,c=0;
    for(int i=0;i<sizeof(st)/sizeof(st[0]);i++){
        if(vp[i].first > curr ){
            curr = vp[i].first;
            c++;
        }
    }
    cout<<c;
    return 0;
}