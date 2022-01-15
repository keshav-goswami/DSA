#include<bits/stdc++.h>
using namespace std;
int mx = 0;

struct Node{
    int val;
    Node* left;
    Node* right;

    Node(int data){
        val = data;
        left = right = NULL;
    }
};
int depth_sum(Node* root){
    if(!root) return 0;

    int lt = max(0,depth_sum(root->left));
    int rt = max(0,depth_sum(root->right));
    // cout<<"L: "<<lt<<endl;
    // cout<<"R: "<<rt<<endl;
    // cout<<"v: "<<root->val<<endl;
    mx = max(mx,lt+rt+root->val);
    return (root->val) + max(lt,rt);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    depth_sum(root);
    cout<<"MAX_SUM: "<<mx;
    return 0;
}