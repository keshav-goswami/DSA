#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> a,pair<int,int> b){
    return a.first>b.first;
}

int main(){
    int profit[] = {100,19,27,25,15}; // taken just for sake of easy input
    int deadl[] = {2,1,2,1,3}; // so that i dont need to enter them again and again
    int N = 5;
    // cin>>N;
    vector<pair<int,int>> vp;
    for(int i=0;i<N;i++){
        vp.push_back(make_pair(profit[i],deadl[i])); 
    }
    sort(vp.begin(),vp.end(),compare); //sorting in desc
    int maxd = -1;
    for(int i=0;i<N;i++){
        if(deadl[i]>maxd) maxd = deadl[i];
    }
    int fill[maxd];
    for(int i=0;i<maxd;i++){
        fill[i] = -1;
    }
    int count = 0;
    for(int i=0;i<N;i++){
        int j = vp[i].second-1;
        while(j>=0 && fill[j]!=-1) j--;
        if(j>=0 && fill[j]==-1){
            fill[j] = abs(vp[i].first);
            count++;
        }
    }
    int sum = 0;
    for(int i=0;i<maxd;i++){
        sum+=fill[i];
    }
    cout<<"MAX_PROFIT: "<<sum<<endl;
    cout<<"JOBS TAKEN: "<<count;
    return 0;
}