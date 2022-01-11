// Q.3 Pascal’s triangle is a triangular array of the binomial coefficients. Write a function that takes an integer value n as input and prints first n lines of the Pascal’s triangle. Following are the first 6 rows of Pascal’s Triangle.

// 1  
// 1 1 
// 1 2 1 
// 1 3 3 1 
// 1 4 6 4 1 
// 1 5 10 10 5 1

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    cout<<endl;
    int arr[n+1][n+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=i;j++){
            if(j == 0) arr[i][j] = 1;
            else if(i == j) arr[i][j] = 1;
            else arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=i;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}