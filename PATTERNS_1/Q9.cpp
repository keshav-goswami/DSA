// Q.9 Write a Program to Print the V Shape Alphabet Pattern.

// E       E 
//  D     D
//   C   C
//    B B
//     A  

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    cout<<endl;
    for(int i=n-1;i>=0;i--){
        for(int j=i;j<n;j++){
            cout<<" ";
        }
        cout<<(char)(i+65);
        for(int j=2*i-1;j>0;j--){
            cout<<" ";
        }
        if(i!=0) cout<<(char)(i+65);
        cout<<endl;
    }
    return 0;
}
