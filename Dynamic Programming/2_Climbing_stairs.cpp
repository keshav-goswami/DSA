#include<bits/stdc++.h>
using namespace std;

// N stairs: 1 2 3
// Recursive Solution
int climbing_stairs(int n){
    // base case
    if(n <= 1) return 1;

    // Do all stuff or function recalling
    int way1 = climbing_stairs(n-1);
    int way2 = climbing_stairs(n-2);
    return way1+way2;
}

// Memoization Method 
vector<int> dp(1000,-1);
int climbing_stairs_memo(int n){
    // base case
    if(n <= 1) return dp[n] = 1;

    //Memoization
    if(dp[n]!=-1) return dp[n];  

    // Do all stuff or function recalling
    int way1 = climbing_stairs_memo(n-1);
    int way2 = climbing_stairs_memo(n-2);
    return dp[n] = way1+way2;
}


// Tabulation Method
int climbing_stairs_tab(int n){
    // base case
    vector<int> dp(1001,-1);
    dp[0] = 1;
    dp[1] = 1;

    for(int i=2;i<=n;i++){
        int way1 = dp[i-1]; 
        int way2 = dp[i-2];
        dp[i] = way1+way2;
    }
    return dp[n];
}
int main(){
    int n;
    cin>>n;

    // int ans = climbing_stairs(n);
    // int ans = climbing_stairs_memo(n);
    int ans = climbing_stairs_tab(n);
    cout<<ans;    
    return 0;
}