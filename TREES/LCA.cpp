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

Node* LCA(Node* root,int a,int b){
    if(!root || root->val == a || root->val == b){
        return root;
    }
    Node* left = LCA(root->left,a,b);
    Node* right = LCA(root->right,a,b);
    if(!left) return right;
    else if(!right) return left;
    else return root;

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
    //                                          1
    //                                   2             3
    //                               4      5       6     7 
    //                                            8   9       

    cout<<LCA(root,8,7)->val;
    return 0;
}