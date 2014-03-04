#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
	Node(int val): data(val), left(NULL), right(NULL){}
};
 
void RangeQuery(Node* root, int k1, int k2)
{
	if(root==NULL)
		return;

	if(root->data > k1)
		RangeQuery(root->left, k1, k2);

	if(root->data >= k1 && root->data <= k2)
		cout << root->data << " ";

	if(root->data < k2)
		RangeQuery(root->right, k1, k2);
}

int main()
{
	Node *root = new Node(4);
	root->left        = new Node(2);
	root->right       = new Node(6);
	root->left->left  = new Node(1);
	root->left->right = new Node(3); 
	root->right->left = new Node(5);
	root->right->right= new Node(7);

	RangeQuery(root, 3, 5);
 
	getchar();
	return 0;
}

//http://www.geeksforgeeks.org/print-bst-keys-in-the-given-range/