#include<bits/stdc++.h>
using namespace std;

bool subset_sum(int *W,int S,int N)
{
    if(S == 0) return true;
    if(N == 0) return false;
    if(W[N-1]>S) return subset_sum(W,S,N-1);
    else return subset_sum(W,S,N-1)||subset_sum(W,S-W[N-1],N-1);
}
int main(){
    int W[] = {3,5,11,42,13,55,67,43,22,13};
    int N = 10;
    // cin>>N;
    int S = 1; // sum to be find 
    if(subset_sum(W,S,N)) cout<<"Exists";
    else cout<<"Doesn't Exist";
    return 0;
}