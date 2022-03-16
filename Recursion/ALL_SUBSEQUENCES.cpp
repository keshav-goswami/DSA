//  Printing all subsequences of array
#include<bits/stdc++.h>
using namespace std;
vector<int> vp;
void display(vector<int> vp){
    int n = vp.size();
    cout<<"[";
    for(int i=0;i<n;i++){
        cout<<vp[i];
        if(i!=n-1) cout<<","; 
    }
    cout<<"]"<<endl;
}
void recurse(int i,vector<int> &nums,int n){
    if(i>=n){
        display(vp);
        return; 
    }
    vp.push_back(nums[i]);
    recurse(i+1,nums,n);
    vp.pop_back(); 
    recurse(i+1,nums,n);
}

int main(){
    vector<int> nums = {3,2,1}; 
    int n = nums.size();
    recurse(0,nums,n);
    return 0;
}