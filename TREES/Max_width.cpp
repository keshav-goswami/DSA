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

int max_width(Node* root){
    if(!root) return 0;
    int ans = 0;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        int mn = q.front().second;
        int size = q.size();
        int ft,lt;
        for(int i=0;i<size;i++){
            int curr_id = q.front().second - mn;
            Node* node = q.front().first;
            q.pop();
            if(i==0) ft = curr_id;
            if(i==size-1) lt = curr_id;
            if(node->left) q.push({node->left,2*curr_id+1});
            if(node->right) q.push({node->right,2*curr_id+2});
        }
        ans = max(ans,lt-ft+1);
    }
    return ans;
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
    root->right->right->right = new Node(9);
    root->left->left->left = new Node(10);
    cout<<max_width(root);
    return 0;
}