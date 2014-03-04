#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

class Node{
public:
	int data;
	Node* left;
	Node* right;

	Node(int val): data(val), left(NULL), right(NULL){}
};

//inorder traversal
void BST2LinkedList(Node* root, Node*& head)
{
	static Node* last = NULL;

	if(root==NULL) return;

	BST2LinkedList(root->left, head);
	
	//the first node discovered in inorder 
	//traversal is the head of the linked list
	if(head == NULL)
	{
		head = root;
	}
	else
	{
		//
		last->right = root;
		root->left = last;
	}	
	//mark the current node as last
	last = root;

	BST2LinkedList(root->right, head);
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

  Node* head = NULL;
  BST2LinkedList(root, head);
  return 0;
}