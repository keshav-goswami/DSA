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


Node* shift_right(Node* root){
    if(root->right){
        root = root->right;
    }
    else{
        return root;
    }
}

Node* helper(Node* root){
    if(!root->left) return root->right;
    if(!root->right) return root->left;
    else{
        Node* right_child = root->right;
        Node* left_mostright = shift_right(root->left);
        left_mostright->right = right_child;
        return root->left;
    }
}

Node* Delete_Node(Node* root,int k){
    if(!root) return NULL;
    if(root->val == k){
        return helper(root);
    }
    Node* cpy = root;
    while(root){
        if(root->val > k){
            if(root->left->val == k){
                root->left = helper(root->left);
                break;
            }
            else root = root->left;
        }
        else{
            if(root->right->val == k){
                root->right = helper(root->right);
                break;
            }
            else root = root->right;
        }
    }
    return cpy;
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
    int key = 8;
    cout<<"AFTER DELETION: "<<endl;
    Node* dummy = Delete_Node(root,key);
    inorder(dummy);
    return 0;
}