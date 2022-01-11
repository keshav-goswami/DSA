// Q.1 Write a Program to print a butterfly shape Number pattern.

// 1     7
// 12   67
// 123 567
// 1234567
// 123 567
// 12   67
// 1     7


#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int x = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j<=x || j>=(n+1-x)){
                cout<<j;    
            }
            else cout<<" ";
        }
        cout<<endl;
        if(i <= n/2) x++;
        else x--;
    }
    return 0;
}