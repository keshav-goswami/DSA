#include<bits/stdc++.h>
using namespace std;
int knapsack(int W[],int V[],int N,int bag){
    //bag == 0 || N == 0
    if(bag == 0 || N == 0) return dp[n] = 0;
    else if(W[N-1]>bag) return dp[n] = knapsack(W,V,N-1,bag); 
    else return dp[n] = max(knapsack(W,V,N-1,bag),V[N-1]+knapsack(W,V,N-1,bag-W[N-1])); 
}
int main(){
    int bag = 60;
    int W[] = {20,30,50,2};
    int V[] = {100,300,500,40};
    int N = 4;
    cout<<"MAX_PROFIT: "<<knapsack(W,V,N,bag);
    return 0;
}