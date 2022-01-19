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
vector<int> topView(Node *root){
    vector<int> vp;
    if(!root) return vp;
    queue<pair<Node*,int>> q;
    map<int,int> mp;
    q.push({root,0});
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        Node* node = p.first;
        int v = p.second;
        mp[v] = node->data;
        if(node->left) q.push({node->left,v-1});
        if(node->right) q.push({node->right,v+1});
    }
    for(auto a:mp){
        vp.push_back(a.second);
    }
    return vp;
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
    vector<int> ans;
    ans = topView(root);
    for(auto a:ans){
        cout<<a<<" ";
    }
    return 0;
}