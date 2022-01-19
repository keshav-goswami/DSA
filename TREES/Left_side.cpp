#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data){
        val = data;
        left = right = NULL;
    }
};
void func(TreeNode* root,int level,vector<int> &vp){
    if(!root) return;
    if(level == vp.size()) vp.push_back(root->val);
    if(root->left) func(root->left,level+1,vp);
    if(root->right) func(root->right,level+1,vp);
}
void rightSideView(TreeNode* root) {
    vector<int> vp;
    func(root,0,vp);
    for(auto a:vp){
        cout<<a<<" ";
    }
}

int main(){    
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    rightSideView(root);
    return 0;
}
