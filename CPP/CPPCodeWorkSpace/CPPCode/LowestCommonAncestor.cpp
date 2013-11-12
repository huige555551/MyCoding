#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node* left;
	Node* right;

	//constructors
	Node(): data(0), left(NULL), right(NULL){}
	Node(int val): data(val), left(NULL), right(NULL){}
};

Node* lowestCommonAncestorBT(Node* root, int n1, int n2)
{
	if(root==NULL) return NULL;
	if(root->data == n1 || root->data == n2) return NULL;

	if(root->left){
		if(root->left->data == n1 || root->left->data == n2)
			return root;
	}
	if(root->right){
		if(root->right->data == n1 || root->right->data == n2)
			return root;
	}
	
	//check left and right both
	Node* left = lowestCommonAncestorBT(root->left, n1, n2);
	Node* right = lowestCommonAncestorBT(root->right, n1, n2);

	if(left && right) return root;
	if(left) return left;
	if(right) return right;

	return NULL;
}

//n1 < n2
Node* lowestCommonAncestorBST(Node* root, int n1, int n2)
{
	if(root==NULL) return NULL;
	if(root->data == n1 || root->data == n2) return NULL;

	if(root->left){
		if(root->left->data == n1 || root->left->data == n2)
			return root;
	}
	if(root->right){
		if(root->right->data == n1 || root->right->data == n2)
			return root;
	}

	if(root->data > n1 && root->data < n2)
		return root;

	if(root->data > n1 && root->data > n2)
		return lowestCommonAncestorBST(root->left, n1, n2);
	if(root->data < n1 && root->data < n2)
		return lowestCommonAncestorBST(root->right, n1, n2);
}


bool covers(Node* root, int p)
{
	if(root==NULL) return false;
	if(root->data == p) return true;
	return (covers(root->left, p) || covers(root->right, p));
}

Node* commonAncestor(Node* root, int p, int q)
{
	if(covers(root->left, p) && covers(root->left, q))
		return commonAncestor(root->left, p, q);

	if(covers(root->right, p) && covers(root->right, q))
		return commonAncestor(root->right, p, q);

	return root;
}

int main()
{
	/* Use the following example tree
	 *      4
	 *   2     6
	 *  1  3  5  7
	 *			   8
	 */

	Node* root = new Node(4);
	root->left = new Node(2);
	root->right = new Node(6);
	root->left->left = new Node(1);
	root->left->right = new Node(3);
	root->right->left = new Node(5);
	root->right->right = new Node(7);
	root->right->right->right = new Node(8);
	
	Node* n1 = lowestCommonAncestorBT(root, 8, 6);
	Node* n2 = lowestCommonAncestorBT(root, 6, 8);
	return 0;
}