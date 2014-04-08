#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
f: 0
c: 100
d: 101
a: 1100
b: 1101
e: 111
*/

class Node {
public:
	char ch;
    int count;
    Node *left, *right;

	Node(char ch1, int val): ch(ch1), count(val), left(NULL), right(NULL){}
	Node(char ch1, int val, Node* l, Node* r): ch(ch1), count(val), left(l), right(r){}
};

class Comparison{
public:
	bool operator() (Node* a, Node* b)
	{
		return (a->count > b->count);
	}
};

Node* makeHuffManTree(char arr[], int freq[], int size)
{
	priority_queue<Node*, vector<Node*>, Comparison> queue;

	for(int i=0; i<size; i++)
	{
		Node* node = new Node(arr[i], freq[i]);
		queue.push(node);
	}

	while(queue.size()>1)
	{
		Node* n1 = queue.top(); queue.pop();
		Node* n2 = queue.top(); queue.pop();

		Node* node = new Node(' ', n1->count + n2->count, n1, n2);

		queue.push(node);
	}

	Node* root = queue.top(); queue.pop();
	return root;
}

void printHuffMancode(Node* root, vector<int> bits = vector<int>())
{
	if(root==NULL)
		return;
	if(root->left == NULL && root->right == NULL)
	{
		cout << root->ch << " ";
		for(int i=0; i<bits.size(); i++) cout << bits[i];
		cout << endl;
	}
	bits.push_back(0);
	printHuffMancode(root->left, bits);
	bits.pop_back();

	bits.push_back(1);
	printHuffMancode(root->right, bits);
	bits.pop_back();
}

int main()
{
	char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr)/sizeof(arr[0]);
    Node* root = makeHuffManTree(arr, freq, size);
	printHuffMancode(root);
	return 0;
}