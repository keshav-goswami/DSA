#include<bits/stdc++.h>
using namespace std;

// int fibo(int n,vector<int> &dp){
//     if(n == 0) return 0;
//     if(n == 1) return 1; 
//     if(dp[n]!=-1) return dp[n];
//     return dp[n] = fibo(n-1,dp) + fibo(n-2,dp); 
// }

int fibo(int n,vector<int> &dp){ 
    dp[0] = 0;
    dp[1] = 1;   
    for(int i=2;i<=n;i++){ 
        dp[i] = dp[i-1]+dp[i-2]; 
    }
    return dp[n]; 
}

int main(){
    int n;
    cin>>n;
    vector<int> vp(n+1,-1);
    cout<<fibo(n,vp);
    return 0;
}