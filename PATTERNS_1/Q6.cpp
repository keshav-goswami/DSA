// Q.6 Write a Program to print the Full Pyramid Number Pattern.

//     1
//    321
//   54321
//  7654321
// 987654321

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<=n;i++){
        for(int j=n-i;j>0;j--){
            cout<<" ";
        }
        for(int j=2*i-1;j>0;j--){
            cout<<j;
        }
        cout<<endl;
    }
    return 0;
}