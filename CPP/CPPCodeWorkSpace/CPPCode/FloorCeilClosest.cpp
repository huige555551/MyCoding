#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Node{
public:
	int data;
	Node* left;
	Node* right;
	Node(int val): data(val), left(NULL), right(NULL){}
};

int Ceil(Node* root, int n)
{
	if(root==NULL)
		return -1;

	if(root->data == n) return n;
	else if(root->data < n) return Ceil(root->right, n);
	else //if(root->data > n)
	{
		int ceil_val = Ceil(root->left, n);

		if(ceil_val >= n) return ceil_val;
		else return root->data;
	}
}
int Floor(Node* root, int n)
{
	if(root==NULL)
		return INT_MAX;

	if(root->data == n) return n;
	else if(root->data > n) return Floor(root->left, n);
	else //if(root->data < n)
	{
		int floor_val = Floor(root->right, n);

		if(floor_val <= n) return floor_val;
		else return root->data;
	}
}

int getDiff(int a, int b)
{
	if(a > b) return a - b;
	else return b - a;
}

int Closest(Node* root, int n, int& minDiff, int& close_val)
{
	//works for 1st function call
	//static int minDiff = INT_MAX;
	//static int close_val = 0;

	if(root==NULL)
		return close_val;

	int diff = getDiff(root->data, n);
	if(diff < minDiff) {
		minDiff = diff;
		close_val = root->data;
	}

	if(root->data == n)
		return n;
	else if(root->data > n) 
		return Closest(root->left, n, minDiff, close_val);
	else //if(root->data < n) 
		return Closest(root->right, n, minDiff, close_val);
}

void main()
{
	Node *root = new Node(40);
	root->left = new Node(20);
	root->left->left = new Node(10);
	root->left->right = new Node(30);
	root->left->right->left = new Node(25);
	root->left->right->right = new Node(35);
	root->right = new Node(60);
	root->right->left = new Node(50);
	root->right->right = new Node(70);

	for(int i=0; i<70; i+=3) cout << i << " -> " << Ceil(root, i) << endl;
	for(int i=0; i<70; i+=3) cout << i << " -> " << Floor(root, i) << endl;
	for(int i=0; i<70; i+=3) {
		int minDiff = INT_MAX;
		int close_val = 0;
		cout << i << " -> " << Closest(root, i, minDiff, close_val) << endl;
	}
	//cout << Closest(root, 18, minDiff, close_val);
}

/*
		40
	20		60
 10	  30  50  70
	25	35
*/