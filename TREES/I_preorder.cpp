#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }  
};
void Iterative_preorder(Node* root){
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        Node* node = st.top();
        cout<<node->data<<" ";
        st.pop();
        if(node->right) st.push(node->right);
        if(node->left) st.push(node->left);
    }
}
int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    Iterative_preorder(root);
    cout<<endl;
    return 0;
}