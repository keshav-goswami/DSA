#include<bits/stdc++.h>
using namespace std;

void recurse(int id,vector<int> &nums,vector<int> &dp,int n,int sum,int s){
        if(id == n){
            if(s == sum){
                for(auto i:dp) cout<<i<<" ";
                cout<<endl;
            }
            return;
        }
    s+=nums[id];
    dp.push_back(nums[id]);
    recurse(id+1,nums,dp,n,sum,s);
    dp.pop_back();
    s-=nums[id]; 
    recurse(id+1,nums,dp,n,sum,s);
}
int main(){
    vector<int> nums = {4,3,2,1};
    vector<int> ds;
    int sum = 3; 
    int n = nums.size();
    recurse(0,nums,ds,n,sum,0); 
    return 0; 
}