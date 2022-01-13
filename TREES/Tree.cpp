//               1                                   
//            2      3
//         4     5 6    7 

//             [2a,1,3a]
//              /     \
//     [4a,2,5a]       [6a,3,7a]
//      /    \           /     \
// [N,4,N]   [N,5,N] [N,6,N]   [N,7,N] 

// DFS

// pre (Root Left Right) ->  1 2 4 5 3 6 7
// In (Left Root Right) ->   4 2 5 1 6 3 7
// Post (Left Right Root) -> 4 5 2 6 7 3 1

// BFS -> Level order traversal  -> 1 2 3 4 5 6 7

// [2 address ,1, 3 address]
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

// Recurssion
void preorder(Node* root){

    if(root == NULL) return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);

}
void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
void postorder(Node *root){
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}
// QUEUE 
// q[]
//  node = [a,7,a]
// [1,2,3,4,5,6,7]

void bfs(Node* root){
    queue<Node*> q;
    q.push(root); //1
    while(!q.empty()){
        Node* v = q.front();
        cout<<v->val<<" ";
        q.pop();
        if(v->left != NULL) q.push(v->left);
        if(v->right != NULL) q.push(v->right);
    }
}
int main(){

    Node* root = new Node(1);
    // [N,1,N]

    root->left = new Node(2);
    root->right = new Node(3);
//             [2a,1,3a]
//              /     \
//     [4a,2,5a]       [6a,3,7a]

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

//             [2a,1,3a]
//              /     \
//     [4a,2,5a]       [6a,3,7a]
//      /    \           /     \
// [N,4,N]   [N,5,N] [N,6,N]   [N,7,N] 

// TRAVERSAL
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    bfs(root);
    return 0;
}

