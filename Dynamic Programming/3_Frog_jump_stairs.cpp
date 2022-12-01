#include<bits/stdc++.h>
using namespace std;

// Height = {10,20,30,10}

// Recursive Solution
int Frog_jump(int ind,vector<int> &H){
    // Base case 
    // Reached the final stair No cost added
    if(ind == 0) return 0;

    //Do all the stuff
    int step1 = Frog_jump(ind-1,H) + abs(H[ind]-H[ind-1]);
    int step2 = INT_MAX;
    if(ind>1) step2 = Frog_jump(ind-2,H)+abs(H[ind]-H[ind-2]);

    return min(step1,step2);
}

// Memoization
vector<int> dp(1001,-1);
int Frog_jump_memo(int ind,vector<int> &H){
    // Base case 
    // Reached the final stair No cost added
    if(ind == 0) return dp[0] = 0;

    // Memoization
    if(dp[ind] != -1) return dp[ind];

    //Do all the stuff
    int step1 = Frog_jump_memo(ind-1,H) + abs(H[ind]-H[ind-1]);
    int step2 = INT_MAX;
    if(ind>1) step2 = Frog_jump_memo(ind-2,H)+abs(H[ind]-H[ind-2]);

    return dp[ind] = min(step1,step2);
}

// Tabulation
int Frog_jump_tab(int ind,vector<int> &H){
    vector<int> dp(1001,-1); 
    // Base case 
    // Reached the final stair No cost added
    dp[0] = 0;

    //Do all the stuff
    for(int i=1;i<=ind;i++){

        int step1 = dp[i-1] + abs(H[i]-H[i-1]);
        int step2 = INT_MAX;
        if(i>1) step2 = dp[i-2] + abs(H[i]-H[i-2]);

        dp[i] = min(step1,step2);
    }
    return dp[ind];
}

int main(){
    int n;
    cin>>n;
    vector<int> H;
    int x;
    for(int i=0;i<n;i++){
        cin>>x; 
        H.push_back(x);
    }
    // Important : keep in mind that u need to send value of N according to index.
    int ans = Frog_jump_tab(n-1,H);
    cout<<ans;
    return 0;
}