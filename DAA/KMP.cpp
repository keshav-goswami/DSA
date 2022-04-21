#include<bits/stdc++.h>
using namespace std;
void LPS(string pat,int n,int *lps){
    int len = 0;
    lps[0] = 0;
    int i=1;
    while(i<n){
        if(pat[i] == pat[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len!=0){
                len = lps[len-1]; 
            } 
            else{                               //if len == 0
                lps[i] = 0;
                i++;
            }
        }
    }
}
int main(){
    int n;
    // cout<<"N: ";
    // cin>>n;
    string pat = "abacc";
    string text = "erwasabjabcabacc";
    n = pat.length();
    int lps[n]; 
    LPS(pat,n,lps);
    cout<<"LPS: ";
    for(int i=0;i<n;i++){
        cout<<lps[i]<<" ";
    }
    cout<<endl;
    int i=0,j=0;  
    int m = text.length();
    while(i<m){
        if(pat[j]==text[i]){
            i++;
            j++;
        }
        if(j == n){
            cout<<"Pattern found at "<<i-j<<endl;
            j = lps[j-1];
        }
        else if(i<m && pat[j]!=text[i]){
            if(j==0) i++;
            else{
                j = lps[j-1];
            }
        }
    }
    return 0;
}