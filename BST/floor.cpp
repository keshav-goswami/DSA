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

int Floor(Node* root,int key){
    int floor = -1;
    while(root){
        if(root->val == key){
         floor = root->val;
            return floor;
        }
        if(root->val < key){
         floor = root->val;
            root = root->right;
        }
        else{
            root = root->left;
        }
    }
    return floor;
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
    cout<<"FLOOR: "<<Floor(root,key);
    return 0;
}