#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int mt[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i == j) mt[i][j] = 0;
        }
    }
    return 0;
}