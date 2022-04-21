#include<bits/stdc++.h>
using namespace std;

int Knapsack(int V[],int W[],int N,int bag){
    if(bag == 0 || N == 0) return 0;
    if(bag < W[N-1]) return Knapsack(V,W,N-1,bag);
    else return max(Knapsack(V,W,N-1,bag),V[N-1]+Knapsack(V,W,N-1,bag-W[N-1]));
}
int main(){
    int bag = 60;
    int W[] = {20,30,50,2};
    int V[] = {100,300,500,40};
    int N = 4;
    // cin>>N;
    cout<<"MAX_PROFIT: "<<Knapsack(V,W,N,bag);
    return 0;
}