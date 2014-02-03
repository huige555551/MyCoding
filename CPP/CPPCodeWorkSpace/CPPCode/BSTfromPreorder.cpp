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

Node* bstPreorder(int arr[], int size, int min=INT_MIN, int max=INT_MAX)
{
	static int index = 0;

	if(index >= size) return NULL;
	if(arr[index] < min || arr[index] > max) return NULL;

	Node* n = new Node(arr[index]);
	index++;

	n->left = bstPreorder(arr, size, min, n->data);
	n->right = bstPreorder(arr, size, n->data, max);

	return n;
}

int main ()
{
    int arr1[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof( arr1 ) / sizeof( arr1[0] );
 
    Node *root = bstPreorder(arr1, size);
 
    /*printf("Inorder traversal of the constructed tree: \n");
    printInorder(root);*/
 
    return 0;
}

