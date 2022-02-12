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

int LCA(Node* root,Node* n1,Node* n2){
    if(root->val < n1->val && root->val < n2->val) return LCA(root->right,n1,n2);
    if(root->val > n1->val && root->val > n2->val) return LCA(root->left,n1,n2);
    return root->val;
}

int main(){
    Node* root = new Node(8);
    root->left = new Node(6);
    root->right = new Node(12);
    root->left->left = new Node(4);
    root->left->right = new Node(7);
    root->right->right = new Node(14);
    root->right->left = new Node(10);
    Node* n1 = new Node(10);
    Node* n2 = new Node(14);
    cout<<"LCA: "<<LCA(root,n1,n2);
    return 0;
}

                            //        8
                            //      /   \ 
                            //     6     12
                            //   /  \   /  \ 
                            //  4    7 10  14  