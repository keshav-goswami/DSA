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

// Inorder of BST is sorted
void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

// Search in Bst
bool search(Node* root,int key){
    if(!root) return false;
    if(root->val == key) return true;
    if(root->val > key){
        return search(root->left,key);
    }
    else{
        return search(root->right,key);
    }
    return false;
}
int main(){
    Node* root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(12);
    root->left->left = new Node(4);
    root->left->right = new Node(7);
    root->right->right = new Node(14);
    root->right->left = new Node(10);
    inorder(root);
    cout<<endl;
    int key = 11;
    cout<<search(root,key);
    return 0;
}