#include<bits/stdc++.h>
using namespace std;

bool recurse(int id,vector<int> &nums,vector<int> &dp,int n,int sum,int s){
        if(id == n){
            if(s == sum){
                for(auto i:dp) cout<<i<<" ";
                cout<<endl;
                return true;
            }
            return false;
        }
    s+=nums[id];
    dp.push_back(nums[id]);
    if(recurse(id+1,nums,dp,n,sum,s)) return true;
    dp.pop_back();
    s-=nums[id]; 
    if(recurse(id+1,nums,dp,n,sum,s)) return true;
    return false;
}
int main(){
    vector<int> nums = {7,6,4,3,2,1};
    vector<int> ds;
    int sum = 5; 
    int n = nums.size();
    recurse(0,nums,ds,n,sum,0); 
    return 0; 
}