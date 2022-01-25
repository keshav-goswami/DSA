#include <iostream>
using namespace std;
struct node
{
	int data;
	struct node *left, *right;
    node(int val){
        data = val;
        left = right = NULL;
    }
};

void printkdistanceNodeDown(node *root, int k)
{
	if (root == NULL || k < 0) return;
	if (k==0)
	{
		cout << root->data << endl;
		return;
	}
	printkdistanceNodeDown(root->left, k-1);
	printkdistanceNodeDown(root->right, k-1);
}
int printkdistanceNode(node* root, node* target , int k)
{
	if (root == NULL) return -1;
	if (root == target)
	{
		printkdistanceNodeDown(root, k);
		return 0;
	}
	int dl = printkdistanceNode(root->left, target, k);
	if (dl != -1)
	{
		if (dl + 1 == k)
			cout << root->data << endl;
		else
			printkdistanceNodeDown(root->right, k-dl-2);
		return 1 + dl;
	}
	int dr = printkdistanceNode(root->right, target, k);
	if (dr != -1)
	{
		if (dr + 1 == k)
			cout << root->data << endl;
		else
			printkdistanceNodeDown(root->left, k-dr-2);
		return 1 + dr;
	}
	return -1;
}
int main()
{
	node * root = new node(0);
	root->right = new node(1);
  	root->right->right = new node(2);
	root->right->right->right = new node(3);
	node * target = root->right;
	printkdistanceNode(root, target, 2);
	return 0;
}
