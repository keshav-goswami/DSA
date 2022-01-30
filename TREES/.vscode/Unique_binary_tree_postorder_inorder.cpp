#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;

    Node(int data){
        val = data;
        left = right = NULL;
    }
};
void Inorder(Node* root){
    if(!root) return;

    Inorder(root->left);
    cout<<root->val<<" ";
    Inorder(root->right);
}

Node* BuildTree(vector<int> inorder,int ist,int iend,vector<int> postorder,int pst,int pend,map<int,int> mp){
    if(pst>pend || ist > iend) return NULL;
    int curr = postorder[pend];
    Node* node = new Node(curr);
    int id = mp[curr];
    int ln = id - ist;
    node->left = BuildTree(inorder,ist,id-1,postorder,pst,pst+ln-1,mp);
    node->right = BuildTree(inorder,id+1,iend,postorder,pst+ln,pend-1,mp);
    return node;
}
int main(){
    vector<int> postorder = {4,5,2,6,7,3,1};
    vector<int> inorder = {4,2,5,1,6,3,7};
    int n = postorder.size();
    map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[inorder[i]] = i;
    }
    Node* root = BuildTree(inorder,0,n-1,postorder,0,n-1,mp);
    Inorder(root);
    return 0;
}