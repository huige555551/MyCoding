#include <iostream>
#include <vector>
#include <queue>
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

void printLevelOrder2(Node* root)
{
	if(!root) return;

	int level = 0;

	vector<Node*> nodes;
	nodes.push_back(root);

	while(1){
		vector<Node*> childs;

		for(int i=0; i<nodes.size(); i++){
			cout << nodes[i]->data << " ";

			if(nodes[i]->left) childs.push_back(nodes[i]->left);
			if(nodes[i]->right) childs.push_back(nodes[i]->right);	
		}
		cout << endl;
		if(childs.size()==0) break;
		
		nodes.clear();
		nodes.assign(childs.begin(), childs.end());

		level++;
	}
}

void printLevelOrder3(Node* root)
{
	if(!root) return;

	queue<Node *> q;
	q.push(root);

	int nodesInCurrentLevel = 1;
	int nodesInNextLevel = 0;

	while(!q.empty())
	{
		root = q.front(); q.pop();
		nodesInCurrentLevel--;
		
		if(root)
		{
			cout<<root->data;
			q.push(root->left);
			q.push(root->right);

			nodesInNextLevel+=2;
		}
		if (nodesInCurrentLevel == 0) 
		{
			cout << endl;
			nodesInCurrentLevel = nodesInNextLevel;
			nodesInNextLevel = 0;
		}
	}
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

	vector<Node*> roots;
	roots.push_back(root);

	printLevelOrder1(roots);
	printLevelOrder2(root);
	printLevelOrder3(root);

	return 0;
}