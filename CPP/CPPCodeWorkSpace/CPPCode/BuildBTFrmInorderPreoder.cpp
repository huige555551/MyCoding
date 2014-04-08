#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;
 
class Node {
public:
    int data;
    Node *left, *right;
	Node(int val): data(val), left(NULL), right(NULL){}
};

Node* buildBT(string& preorder, string inorder)
{
	if(inorder.empty()) return NULL;

	Node* n = new Node(preorder[0]);

	int pos = inorder.find_first_of(preorder[0]);
	string left = inorder.substr(0, pos);
	string right = inorder.substr(pos+1);
	preorder = preorder.substr(1);

	n->left = buildBT(preorder, left);
	n->right = buildBT(preorder, right);

	return n;
}

void printLevelOrder1(vector<Node*> nodes)
{
	if(nodes.empty()) return;
	
	vector<Node*> childs;

	for(int i=0; i<nodes.size(); i++)
	{
		//print the node
		cout << nodes[i]->data << " ";
		
		//insert the children in vector
		if(nodes[i]->left) childs.push_back(nodes[i]->left);
		if(nodes[i]->right) childs.push_back(nodes[i]->right);
	}
	cout << endl;

	printLevelOrder1(childs);
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

  string inorder = "DBEAFC";
  string preorder = "ABDECF";

  Node* n = buildBT(preorder, inorder);

  vector<Node*> v;
  v.push_back(n);
  printLevelOrder1(v);

  return 0;
}