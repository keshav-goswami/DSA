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

Node* Insert_Node(Node* root,int data){
    if(!root) return new Node(data);
    Node* curr = root;
    while(root){
        if(root->val < data){
            if(root->right) root = root->right;
            else {
                root->right = new Node(data);
                break;
            }
        }
        else{
            if(root->left) root = root->left;
            else{
                root->left = new Node(data);
                break;
            }
        }
    }
    return curr;
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
    int key = 9;
    cout<<"AFTER INSERTION: "<<endl;
    Node* dummy = Insert_Node(root,key);
    inorder(dummy);
    return 0;
}