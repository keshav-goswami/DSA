// Q.4 Given the value of n, print the arrow pattern. 
// Input: n = 5

// Output: 
//  *
//   **
//    ***
//     ****
//      *****
//     ****
//    ***
//   **
//  *

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    cout<<endl;

    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            cout<<" ";
        }
        for(int j=0;j<i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=n-1;i>0;i--){
        for(int j=1;j<i;j++){
            cout<<" ";
        }
        for(int j=0;j<i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}