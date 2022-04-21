#include<bits/stdc++.h>
using namespace std;
// int LCS(string X,string Y,int n,int m){
//     if(n==0 || m==0) return 0;
//     if(X[n-1] == Y[m-1]) return 1 + LCS(X,Y,n-1,m-1);
//     else return max(LCS(X,Y,n-1,m),LCS(X,Y,n,m-1));
// }
int main(){
    string X = "AGCTGGCTAGTTCAG";
    string Y = "GTGCATGTCGTTA";
    int n = X.length();
    int m = Y.length();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0) dp[i][j] = 0;
            else if(X[i-1] == Y[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[n][m];
    return 0;
}