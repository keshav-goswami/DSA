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
void add_left_Boundary(Node* root, vector<Node*> &vp){
    if(!root) return;
    Node* curr = root;
    while(curr){
        if(curr->left || curr->right) vp.push_back(curr);
        if(curr->left) curr = curr->left;
        else curr = curr->right; 
    }
}
void add_right_Boundary(Node* root, vector<Node*> &vp){
    if(!root) return;
    Node* curr = root->right;
    vector<Node*> tmp;
    while(curr){
        if(curr->left || curr->right) tmp.push_back(curr);
        if(curr->right) curr = curr->right;
        else curr = curr->left; 
    }
    for(int i=tmp.size()-1;i>=0;i--){
        vp.push_back(tmp[i]);
    }
}
void add_leaf_Nodes(Node* root, vector<Node*> &vp){
    if(!root) return;
    if(!root->left && !root->right) vp.push_back(root);
    
    if(root->left) add_leaf_Nodes(root->left,vp);
    if(root->right) add_leaf_Nodes(root->right,vp);
}
void  Boundary_Traversal(Node* root){
    vector<Node*> vp;
    add_left_Boundary(root,vp);
    add_leaf_Nodes(root,vp);
    add_right_Boundary(root,vp);
    int n = vp.size();
    for(int i=0;i<n;i++) cout<<vp[i]->val<<" ";
}
int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->left = new Node(8);
    root->right->left->right = new Node(9);
    root->right->right->left = new Node(10);
    root->right->right->right = new Node(11);
    Boundary_Traversal(root);
    return 0;
}