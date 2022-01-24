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
void bfs(Node* root){
    if(!root) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* node = q.front();
        cout<<node->val<<" ";
        q.pop();
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
    }
}
//Tree should satisfy child sum property 
//You are allowed to increase the value of nodes only u can't decrease it
void child_sum(Node* &root){
    if(!root) return;
    int child = 0;
    if(root->left) child+=root->left->val;
    if(root->right) child+=root->right->val;
    if(child >= root->val) root->val = child;
    else{
        if(root->left) root->left->val = root->val;
        if(root->right) root->right->val = root->val;
    }
    child_sum(root->left);
    child_sum(root->right);
    int sm = 0;
    if(root->left) sm += root->left->val;
    if(root->right) sm += root->right->val;
    if(root->left || root->right) root->val = sm;
}
int main(){
    Node *root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->left = new Node(10);
    root->right->right->right = new Node(11);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    bfs(root);
    child_sum(root);
    cout<<endl;
    bfs(root);
    return 0;
}

// starting tree
//                                     10
//                               2             3                 
//                          4       5       6      7
//                       8     9         10           11
// recursive calls
//                                     10
//                               10             13                 
//                          17        10     10     11
//                       8     9          10           11

// back_tracking
//                                      48
//                               27             21                 
//                          17        10     10      11
//                       8     9         10            11

