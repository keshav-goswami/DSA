#include<bits/stdc++.h>
using namespace std;
void hanoi(int n,char S,char D,char A){
    if(n == 0) return;
    hanoi(n-1,S,A,D);
    cout<<"SHIFTING DISK "<<n<<" FROM "<<S<<" TO "<<D<<endl;
    hanoi(n-1,A,D,S);
}
int main(){
    int n;
    cin>>n;
    hanoi(n,'S','D','A');
    return 0;
}