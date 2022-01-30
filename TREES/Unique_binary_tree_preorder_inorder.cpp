// OPTIMIZED CODE TIME COMPLEXITY O(N)

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

Node* BuildTree(vector<int> inorder,int ist,int iend,vector<int> preorder,int pst,int pend,map<int,int> mp){
    if(pst>pend || ist > iend) return NULL;
    int curr = preorder[pst];
    Node* node = new Node(curr);
    int id = mp[curr];
    int ln = id - ist;
    node->left = BuildTree(inorder,ist,id-1,preorder,pst+1,pst+ln,mp);
    node->right = BuildTree(inorder,id+1,iend,preorder,pst+ln+1,pend,mp);
    return node;
}
int main(){
    vector<int> preorder = {1,2,4,5,3,6,7};
    vector<int> inorder = {4,2,5,1,6,3,7};
    int n = preorder.size();
    map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[inorder[i]] = i;
    }
    Node* root = BuildTree(inorder,0,n-1,preorder,0,n-1,mp);
    Inorder(root);
    return 0;
}