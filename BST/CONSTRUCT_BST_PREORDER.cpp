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

Node* buildtree(Node* &root,int a){
    if(!root) 
        return root = new Node(a);
    
    if(root->val > a) return buildtree(root->left,a);
    return buildtree(root->right,a);
} 
Node* bstFromPreorder(vector<int>& preorder) {
    Node* root = NULL;
    
    for(auto a:preorder){
        buildtree(root,a);
    }
    return root;
}
void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
int main(){
    vector<int> preorder;
    preorder = {8,5,1,7,10,12,11};
    Node* root = bstFromPreorder(preorder);
    inorder(root);
    return 0;
}