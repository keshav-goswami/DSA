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

bool get_path(Node* root,int x,vector<int> &vp){
    if(!root) return false;
    vp.push_back(root->val);
    if(root->val == x) return true;

    if(get_path(root->left,x,vp) || get_path(root->right,x,vp)) return true;
    vp.pop_back();
    return false;
}

vector<int> root_to_node(Node* root,int x){
    vector<int> vp;
    if(!root) return vp;
    get_path(root,x,vp);
    return vp;
}
int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    root->right->right->right = new Node(9);
    vector<int> vp;
    vp = root_to_node(root,9);
    for(auto a:vp) cout<<a<<" ";
    return 0;
}