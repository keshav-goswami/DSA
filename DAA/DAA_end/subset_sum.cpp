#include<bits/stdc++.h>
using namespace std;
// bool subset(int A[],int S,int N){
//     if(N == 0) return false;
//     if(S == 0) return true;
//     if(S < A[N-1]) return subset(A,S,N-1);
//     else return subset(A,S,N-1) || subset(A,S-A[N-1],N-1);
// }
int main(){
    int A[] = {5,4,3,1};
    int N = sizeof(A)/sizeof(A[0]);
    int S = 7;
    bool dp[5][8];
    for(int i=0;i<=N;i++){
        for(int j=0;j<=S;j++){
            if(i==0) dp[i][j] = false;
            if(j==0) dp[i][j] = true;
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=S;j++){
            if(j < A[i-1]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = dp[i-1][j] || dp[i-1][j-A[i-1]];
        }
    }
    for(int i=0;i<=N;i++){
        for(int j=0;j<=S;j++){ 
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    // cout<<"SUM FIND: "<<subset(A,S,N);
    cout<<"SUM FIND: "<<dp[N][S];
    return 0;
}