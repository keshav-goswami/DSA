// Q.4 Write a Program to print the Full Pyramid Star pattern.
//     *  
//    * * 
//   * * *
//  * * * *
// * * * * *

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<=n;i++){
        for(int j=i;j<n;j++){
            cout<<" ";
        }
        for(int j=0;j<i;j++){
            cout<<" *";
        }
        cout<<endl;
    }
    return 0;
}