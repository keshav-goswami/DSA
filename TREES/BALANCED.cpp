// Its time complexity is O(N)
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        val = data;
        left = right = NULL;
    }
};

int maxdepth(Node* root){
    if(!root) return 0;
    int left = maxdepth(root->left);
    if(left == -1) return -1;
    int right = maxdepth(root->right);
    if(right == -1) return -1;
    
    if(abs(left-right)>1) return -1;
    return 1 + max(left,right);
}
bool check(Node *root){
    return maxdepth(root)!=-1;
}
int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->left = new Node(8);
    root->right->left->right = new Node(9);
    cout<<"BALANCED TREE: ";
    if(check(root)) cout<<"true";
    else cout<<"false";
    return 0;
}