// Q.10 Write a Program to Print Cross Sign (╳ ) Number Pattern.

// 1   1
//  2 2
//   3
//  4 4
// 5   5

#include<bits/stdc++.h>
using namespace std;

int main()
{ 
    int n; 
    cin>>n;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) 
        {
            if (j == i || j == (n + 1 - i))
                cout << i; 
            else
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}