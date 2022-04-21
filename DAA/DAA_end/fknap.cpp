#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int,int> p1,pair<int,int> p2){
    double v1 = (double) p1.second/p1.first;
    double v2 = (double) p2.second/p2.first;
    return v1>v2;
}
int main(){
    int bag = 60;
    int W[] = {20,30,50,2};
    int V[] = {100,300,500,40};
    int N = 4;
    vector<pair<int,int>> vp;
    for(int i=0;i<N;i++){
        vp.push_back(make_pair(W[i],V[i]));
    }
    sort(vp.begin(),vp.end(),compare);
    int profit=0;
    for(int i=0;i<N;i++){
        if(bag>=vp[i].first){
            bag-=vp[i].first;
            profit+=vp[i].second;
            continue;
        }
        double vw = (double) vp[i].second/vp[i].first;
        profit+=vw*bag;
        bag = 0;
        break;
    }
    cout<<profit;
    return 0;
}