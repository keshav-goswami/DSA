#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        val = data;
        left = right = NULL;
    }
};
// MAXIMUM DEPTH OR HEIGHT
int depth(Node* root){
    if(!root) return 0;
    int lt = depth(root->left);
    int rt = depth(root->right);
    return 1 + max(lt,rt);
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
    cout<<"DEPTH: "<<depth(root);
    return 0;
}