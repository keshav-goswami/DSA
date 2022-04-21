#include<bits/stdc++.h>
using namespace std;
void heapify(int *A,int n,int i){
    int c1 = 2*i+1;
    int c2 = 2*i+2;
    int maxm = i;
    if(c1<n && A[c1]>A[maxm]){
        maxm = c1;
    }
    if(c2<n && A[c2]>A[maxm]){
        maxm = c2;
    }
    if(maxm!=i){
        swap(A[i],A[maxm]);
        heapify(A,n,maxm);
    }
}
void build_heap(int *A,int n){
    for(int i = n/2;i>=0;i--){
        heapify(A,n,i);
    }
}
int extract_max(int *A,int &n){
    int mx = A[0];
    swap(A[0],A[n-1]);
    n--;
    build_heap(A,n);
    return mx;
}
int main(){
    int A[] = {3,9,4,5,1,2};
    int n = 6;
    build_heap(A,n);
    for(int i=0;i<n;i++) cout<<A[i]<<" ";
    stack<int> st;
    int N = n;
    for(int i=0;i<N;i++){
        st.push(extract_max(A,n));
    }
    cout<<endl;
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}