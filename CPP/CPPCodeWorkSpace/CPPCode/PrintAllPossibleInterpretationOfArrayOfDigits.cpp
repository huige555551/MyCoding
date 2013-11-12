//source: http://www.geeksforgeeks.org/find-all-possible-interpretations/
#include <iostream>
#include <string>
using namespace std;

class Node{
public:
	string data;
	Node* left;
	Node* right;

	Node() {
		data = "";
		left = NULL;
		right = NULL;
	}

	Node(string str) {
		data = str;
		left = NULL;
		right = NULL;
	}
};

string alphabet[] = {"", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

Node* createBTree(int arr[], int size, int index=0, string str="")
{
	Node* root = new Node(str);

	if(index==size) return root;	
	
	string leftStr = str + alphabet[arr[index]];
	root->left = createBTree(arr, size, index+1, leftStr);

	if(size - index >= 2){
		int num = arr[index] * 10 + arr[index+1];
		
		if(num <= 26) {
			string rightStr = str + alphabet[num];
			root->right = createBTree(arr, size, index+2, rightStr);
		}
	}

	return root;
}

void printLeaves(Node* root)
{
	if(root==NULL) return;
	if(root->left==NULL && root->right==NULL) 
		cout << root->data << endl;
	printLeaves(root->left);
	printLeaves(root->right);
}

void printAllInterpretations(int arr[], int size)
{
	Node* root = createBTree(arr, size);
	printLeaves(root);
	cout << endl;
}

int main() {

	// aacd(1,1,3,4) amd(1,13,4) kcd(11,3,4)
    // Note : 1,1,34 is not valid as we don't have values 
	// corresponding to 34 in alphabet
    int arr[] = {1, 1, 3, 4};	
    printAllInterpretations(arr, 4);
 
    // aaa(1,1,1) ak(1,11) ka(11,1)
    int arr2[] = {1, 1, 1};	
    printAllInterpretations(arr2, 3);
 
    // bf(2,6) z(26)
    int arr3[] = {2, 6};	
    printAllInterpretations(arr3, 2);
 
    // ab(1,2), l(12)  
    int arr4[] = {1, 2};
    printAllInterpretations(arr4, 2);
 
    // a(1,0} j(10)  
    int arr5[] = {1, 0};
    printAllInterpretations(arr5, 2);
 
    // "" empty string output as array is empty
    //int arr6[] = {};
    //printAllInterpretations(arr6);
 
    // abba abu ava lba lu
    int arr7[] = {1, 2, 2, 1};
    printAllInterpretations(arr7, 4);

	return 0;
}

