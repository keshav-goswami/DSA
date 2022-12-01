#include<bits/stdc++.h>
using namespace std;
// indeces: 0 1 2 3 4 5 6  7  8  9 10
// FIBO:    0 1 1 2 3 5 8 13 21 34 55  

// Basic Recursion
int fib(int n){
    // base case
    if(n == 0 || n == 1) return n;
    // function calling
    return fib(n-1)+fib(n-2);
}

// Conversion to Dp: 
// Number of variable = 1
// Therefore dimension of DP array = 1

// 1)Memoization
vector<int> dp(1001,-1);
int dp_fib(int n){
    // base case
    if(n == 0 || n == 1) return dp[n] = n;

    // Memoization Use
    if(dp[n]!=-1) return dp[n]; 

    // function calling
    return dp[n] = dp_fib(n-1)+dp_fib(n-2);
}

// 2) Tabulation 

int dp2_fib(int n){
    vector<int> dp(1000,-1);
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}

// 3) Space Optimization Tabulation 
//          P2 P1 ci
// indeces: 0  1  2  3  4  5  6  7  8  9  10
int dp2o_fib(int n){
    int P2 = 0;
    int P1 = 1;
    int ci = 0;
    
    for(int i=2;i<=n;i++){
        ci = P2+P1;
        P2 = P1;
        P1 = ci;
    }
    return ci;
}



int main(){
    int n;
    cin>>n;
    int ans = dp2o_fib(n);
    cout<<ans;
    return 0;
}