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

vector<vector<int>> zigzagLevelOrder(Node* root) {
    vector<vector<int>> res;
    if(!root) return res;
    queue<Node*> q;
    q.push(root);
    bool ltor = false;
    while(!q.empty()){
        int size = q.size();
        vector<int> row;
        for(int i=0;i<size;i++){
            Node* Node = q.front();
            q.pop();
            row.push_back(Node->val);
            // cout<<Node->val;
            if(Node->left) q.push(Node->left);
            if(Node->right) q.push(Node->right);
        }
        if(ltor) reverse(row.begin(),row.end());
        ltor = !ltor;
        res.push_back(row);
    }
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return res;
}
int main(){
    vector<vector<int>> vp;
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->left = new Node(8);
    root->right->left->right = new Node(9);
    root->right->right->left = new Node(10);
    root->right->right->right = new Node(11);
    vp = zigzagLevelOrder(root);
    return 0;
}