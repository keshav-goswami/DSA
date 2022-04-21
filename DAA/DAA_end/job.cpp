#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> p1,pair<int,int> p2){
    return p1.first>p2.first;
}
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> vp;
    for(int i=0;i<n;i++){
        int pr,ed;
        cin>>pr>>ed;
        vp.push_back(make_pair(pr,ed));
    }
    sort(vp.begin(),vp.end(),compare);
    int mx = -9999;
    for(int i = 0;i<vp.size();i++){
        if(vp[i].second > mx){
            mx = vp[i].second;
        }
    }
    cout<<mx<<endl;
    int fill[mx];
    int sum = 0;
    for(int i=0;i<mx;i++) fill[i] = -1;
    for(int i=0;i<n;i++){
        int j = vp[i].second - 1;
        while(j>=0 && fill[j]!=-1) j--;
        if(j>=0 && fill[j]==-1){
            fill[j] = vp[i].first;
            sum+=vp[i].first;
        }
    }
    cout<<sum;
    return 0;
}