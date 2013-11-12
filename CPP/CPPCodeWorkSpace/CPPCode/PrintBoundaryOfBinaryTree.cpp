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

bool isLeaf(Node* root)
{
	if(root->left==NULL && root->right==NULL)
		return true;

	return false;
}

//kind of preorder
void printLeftOnly(Node* root)
{
	if(root==NULL) return;
	
	if(!isLeaf(root)) 
		cout << root->data << " "; //to avoid duplicates
	
	printLeftOnly(root->left);	
}

//kind of postorder
void printRightOnly(Node* root)
{
	if(root==NULL) return;
	
	printRightOnly(root->right);
	
	if(!isLeaf(root)) 
		cout << root->data << " ";
}

//kind of inorder
void printLeafOnly(Node* root)
{
	if(root==NULL) return;

	printLeafOnly(root->left);
	
	if(isLeaf(root)) 
		cout << root->data << " ";
	
	printLeafOnly(root->right);
}

void printBoundary(Node* root)
{
	printLeftOnly(root);
	printLeafOnly(root);
	printRightOnly(root);
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

	printBoundary(root);

	return 0;
}