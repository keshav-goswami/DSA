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

Node* TreetoLinkedList(Node* root){
    if(!root) return NULL;
    Node* curr = root;
    while(curr){
        if(curr->left){
            Node* lt = curr->left;
            while(lt->right){
                lt = lt->right;
            }
            lt->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
    return root;
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
    bfs(root);
    cout<<endl;
    Node* list = TreetoLinkedList(root);
    while(list){
        cout<<list->val<<" ";
        list = list->right;
    }
    return 0;
}