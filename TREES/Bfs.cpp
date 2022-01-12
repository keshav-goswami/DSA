#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val){
        data = val;
        left = right = NULL;
    }
};
void BFS(TreeNode* root){
    vector<int> bfs;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();
        bfs.push_back(node->data);
        if(node->left != NULL) q.push(node->left);
        if(node->right != NULL) q.push(node->right);
    }
    for(int i=0;i<bfs.size();i++){
        cout<<bfs[i]<<" ";
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
    BFS(root);
    return 0;
}
