#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int,int> a,pair<int,int> b){
    double v1 =(double) a.first/a.second;
    double v2 =(double) b.first/b.second;
    return v1>v2;
}
int main(){
    int bag = 60;
    int W[] = {20,30,50,2};
    int V[] = {100,300,500,40};
    int N = 4;
    // cin>>N;
    vector<pair<int,int>> vp;
    for (int i = 0; i < N; i++)
    {
        vp.push_back(make_pair(V[i],W[i]));
    }
    sort(vp.begin(),vp.end(),compare); // desc
    int sum = 0;
    for(int i=0;i<N;i++){
        if(bag>=vp[i].second){
            bag-=vp[i].second;
            sum+=vp[i].first;
            continue;
        }
        double vw = (double) vp[i].first/vp[i].second;
        sum+=vw*(bag);
        break;
    }
    cout<<"MAX_PROFIT: "<<sum;
    return 0;
}