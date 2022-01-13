//  Its time complexity is O(N^N)

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
    return 1 + max(maxdepth(root->left),maxdepth(root->right));
}
bool check(Node *root){
    if(root == NULL) return true;
    int lt = maxdepth(root->left);
    int rt = maxdepth(root->right);
    if(abs(lt-rt)>1) return false;
    bool left = check(root->left);
    bool right = check(root->right);

    if(!(left||right)) return false;
    return true;
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
    cout<<"BALANCED TREE: ";
    if(check(root)) cout<<"true";
    else cout<<"false";
    return 0;
}