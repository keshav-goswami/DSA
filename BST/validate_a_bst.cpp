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

bool validate(Node* root,long mn,long mx){
    if(!root) return true;
    if(root->val >= mx || root->val <= mn) return false;
    return validate(root->left,mn,root->val) && validate(root->right,root->val,mx);
}

int main(){
    Node* root = new Node(8);
    root->left = new Node(6);
    root->right = new Node(12);
    root->left->left = new Node(4);
    root->left->right = new Node(7);
    root->right->right = new Node(14);
    root->right->left = new Node(10);
    if(validate(root,LONG_MIN,LONG_MAX)) cout<<"TRUE";
    else cout<<"FALSE";
    return 0;
}