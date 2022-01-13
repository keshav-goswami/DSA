#include<bits/stdc++.h>
using namespace std;
int mx = -999;
struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        data = val;
        left = right = NULL;
    }
};
//  Diameter of every node = (lt+rh);
int Depth(TreeNode* root){
    if(!root) return 0;
    
    int lt = Depth(root->left);
    int rt = Depth(root->right);
    mx = max(mx,lt+rt);
    return 1 + max(lt,rt);
}
int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(4);
    root->left->right = new TreeNode(6);
    root->left->right->right = new TreeNode(7);
    root->left->right->right->right = new TreeNode(8);
    root->left->right->right->right->left = new TreeNode(9);
    root->left->right->right->right->left->right = new TreeNode(10);
    Depth(root);
    cout<<mx<<" ";
    return 0;
}