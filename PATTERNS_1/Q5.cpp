// Q.5 Write a program to Print a solid Diamond Star Pattern.
//      *      
//     * *     
//    * * *    
//   * * * *   
//  * * * * *  
// * * * * * * 
//  * * * * *  
//   * * * *   
//    * * *    
//     * *
//      *

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<=n/2;i++){
        for(int j=i;j<n/2;j++){
            cout<<" ";
        }
        for(int j=0;j<i;j++){
            cout<<" *";
        }
        cout<<endl;
    }
    
    for(int i=n/2;i>0;i--){
        for(int j=n/2+1;j>i;j--){
            cout<<" ";
        }
        for(int j=i-1;j>0;j--){
            cout<<" *";
        }
        cout<<endl;
    }
    return 0;
}