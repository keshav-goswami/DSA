// Q.8 Write a Program to Print the Hollow Diamond Number Pattern.
//     1    
//    2 2
//   3   3
//  4     4
// 5       5
//  4     4
//   3   3
//    2 2
//     1

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=n;j>i;j--){
            cout<<" ";
        }
        cout<<i+1;
        for(int j=0;j<2*i-1;j++){
            cout<<" ";
        }
        if(i!=0) cout<<i+1;
        cout<<endl;
    }
    for(int i=n-2;i>=0;i--){
        for(int j=i;j<n;j++){
            cout<<" ";
        }
        cout<<i+1;
        for(int j=2*i-1;j>0;j--){
            cout<<" ";
        }
        if(i!=0) cout<<i+1;
        cout<<endl;
    }
    return 0;
}