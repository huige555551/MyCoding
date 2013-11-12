#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
 
class Node {
public:
    int data;
    Node *left, *right;
	Node(int val): data(val), left(NULL), right(NULL){}
};
 
/* Returns true if the given tree is a BST and its values are >= min and <= max. */
int isBSTcheck(Node* node, int min, int max)
{  
  if (node==NULL) return 1;
 
  if (node->data < min || node->data > max) return 0; 
 
  /* otherwise check the subtrees recursively, tightening the min or max constraint */
  return	isBSTcheck(node->left, min, node->data-1) && 
			isBSTcheck(node->right, node->data+1, max);
} 
 
int isBST(Node* node)
{
  return isBSTcheck(node, INT_MIN, INT_MAX);
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

 
  if(isBST(root))
    printf("Is BST");
  else
    printf("Not a BST");
 
  getchar();
  return 0;
}