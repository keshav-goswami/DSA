// Q.2 Write a Program to print the Fibonacci Half Pyramid Pattern.

// 1 
// 1 2
// 3 5 8
// 13 21 34 55
// 89 144 233 377 610

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    cout<<endl;
    int size = n*(n+1)/2+1;
    int arr[size],k=0;
    arr[0] = 1;
    arr[1] = 1; 
    for(int i=2;i<size;i++){
        arr[i] = arr[i-1]+arr[i-2];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++,k++){
            cout<<arr[k]<<" ";
        }
        cout<<endl;
    }
    return 0;
}