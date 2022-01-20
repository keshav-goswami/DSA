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
bool isSymmetricalUtil(Node* lt,Node* rt){
    if(lt == NULL || rt == NULL) return lt == rt;
    if(lt->val == rt->val){
        return isSymmetricalUtil(lt->left,rt->right) && isSymmetricalUtil(lt->right,rt->left);
    }
    return false;
}
bool isSymmetrical(Node* root){
    return root == NULL || isSymmetricalUtil(root->left,root->right);
}
int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(3);
    root->right->left = new Node(4);
    root->right->left->right = new Node(5);

    if(isSymmetrical(root)) cout<<"True";
    else cout<<"False";
    return 0;
}