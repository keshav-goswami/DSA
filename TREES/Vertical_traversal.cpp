
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
void vertical_traversal(Node* root){
    map<int,map<int,multiset<int>>> mp;
    queue<pair<Node*,pair<int,int>>> q;
    q.push({root,{0,0}});
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        Node* node = p.first;
        int v = p.second.first , l = p.second.second;
        mp[v][l].insert(node->data);
        if(node->left){
            q.push({node->left,{v-1,l+1}});
        }
        if(node->right){
            q.push({node->right,{v+1,l+1}});
        }
    }
    vector<vector<int>> ans;
    for(auto a: mp){
        vector<int> v;
        for(auto b:a.second){
            v.insert(v.end(),b.second.begin(),b.second.end());
        }
        ans.push_back(v);
    }
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
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
    root->right->left->left = new Node(8);
    root->right->left->right = new Node(9);
    vertical_traversal(root);
    return 0;
}