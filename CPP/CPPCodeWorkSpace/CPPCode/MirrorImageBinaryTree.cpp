#include<iostream>
using namespace std;

class Node{
public:
	int data;
	Node* left;
	Node* right;
	Node(int val): data(val), left(NULL), right(NULL){}
};

void swap(Node*& n1, Node*& n2)
{
	Node* temp;
	temp = n1;
	n1 = n2;
	n2 = temp;
}


void mirror(Node* root) 
{
	if (root==NULL) 
		return;  

	swap(root->left, root->right); 

    mirror(root->left);
    mirror(root->right); 
} 

int main()
{
	/* Use the following example tree
	 *     1
	 *   2    3
	 *  4  5  6 7
	 *    8 
	 */

	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	root->left->right->left = new Node(8);

	mirror(root);
}