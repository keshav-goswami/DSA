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
void Iterative_postorder(Node* root){
    stack<Node*> st,st1;
    st.push(root);
    Node* node = st.top();
    while(!st.empty()){
        node = st.top();
        st.pop();
        st1.push(node);
        if(node->left) st.push(node->left);
        if(node->right) st.push(node->right);
    }
    while(!st1.empty()){
        Node* t = st1.top();
        cout<<t->data<<" ";
        st1.pop();
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
    Iterative_postorder(root);
    cout<<endl;
    return 0;
}