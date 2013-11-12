#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

class Node{
public:
	int data;
	Node* left;
	Node* right;
};

int input[] = {4,2,3,6,5,7};

void createBSTreadingPreOrder(int min_val, int max_val, Node*& node)
{
	static int index = 0;

	int val = input[index];
	
	if(val<min_val || val > max_val) 
		return;

	node = new Node();
	node->data = val;
	node->left = node->right = NULL;
	
	index++;

	if(index < sizeof(input)/sizeof(input[0]))
	{
		createBSTreadingPreOrder(min_val, val, node->left);
		createBSTreadingPreOrder(val, max_val, node->right);
	}
}

void createBSTreadingFilePreOrder(int min_val, int max_val, int &val, Node*& node, ifstream& fin)
{
	if(val<min_val || val > max_val) 
		return;

	node = new Node();
	node->data = val;
	node->left = node->right = NULL;
	
	if(fin>>val)
	{
		createBSTreadingFilePreOrder(min_val, node->data, val, node->left, fin);
		createBSTreadingFilePreOrder(node->data, max_val, val, node->right, fin);
	}
}

void preorder(Node * node)
{
	if(node==NULL) return;
	cout << node->data << " ";
	preorder(node->left);
	preorder(node->right);
}

void insert(Node *& ptr, int num)
{
	if(ptr==NULL){
		ptr = new Node();
		ptr->data = num;
		ptr->left = ptr->right = NULL;		
		return;
	}

	if(num < ptr->data)
		insert(ptr->left, num);
	else if(num > ptr->data)
		insert(ptr->right, num);
	else return;
}

Node* search(Node * root, int num, Node *& ptr, Node* & parent, int &found)
{
	if(root==NULL){
		ptr = root;
		found = 0;
	}
	
	ptr=root;
	while(ptr!=NULL)
	{
		if(num<ptr->data){
			parent = ptr;
			ptr=ptr->left;
		}
		else if(num>ptr->data){
			parent = ptr;
			ptr=ptr->right;
		}
		else {
			found = 1;
			break;
		}
	}

	return ptr;
}

int depth(Node* root)
{
	if(root==NULL) return 0;
	int a = depth(root->left) + 1;
	int b = depth(root->right) + 1;
	
	if(a>b) return a;
	else return b;
}

int height(Node* root)
{
	if(root==NULL) return 0;
 
	return max(height(root->left), height(root->right)) + 1;
}



//Node* commonAncestorBT(Node* root, int p, int q)
//{
//	if(root==NULL) return NULL;
//	
//	if(root->left != NULL){
//		if(root->left->data == p || root->left->data == q)
//			return root;
//	}
//	if(root->right != NULL){
//		if(root->right->data == p || root->right->data == q)
//			return root;
//	}
//	
//	Node* left  = commonAncestorBT(root->left, p, q);
//	Node* right = commonAncestorBT(root->right, p, q);
//
//	if(left && right)
//		return root;
//	else if(left)
//		return left;
//	else 
//		return right;
//}

int howManyFound(Node* root, int p, int q) 
{
	int ret = 0;
	if (root == NULL) return ret;
	
	if (root->data == p || root->data == q) 
		ret += 1;

	ret += howManyFound(root->left, p, q);

	if(ret == 2) // Found p and q
		return ret;
	
	return ret + howManyFound(root->right, p, q);
}

void everyPath(Node* root, int level, vector<int>& buffer = vector<int>())
{
	if(root==NULL) return;

	buffer.push_back(root->data);

	for(int i=0; i<level; i++)
	{
		cout << buffer[i] << " ";
	}
	cout<< endl;

	vector<int> leftBuffer(buffer);
	vector<int> rightBuffer(buffer);

	everyPath(root->left, level+1, leftBuffer);
	everyPath(root->right, level+1, rightBuffer);

}

int Ceil(Node *root, double input)
{
    // Base case
    if( root == NULL )
        return -1;

    // We found equal key
    if( root->data == input )
		return root->data;

    // If root's key is smaller, ceil must be in right subtree
    if( root->data < input )
        return Ceil(root->right, input);

    // Else, either left subtree or root has the ceil value
    int ceil = Ceil(root->left, input);
    return (ceil >= input) ? ceil : root->data;
}

void main()
{
	/*Node* root = NULL;
	createBSTreadingPreOrder(INT_MIN, INT_MAX, root);
	preorder(root);*/

	/*cout << endl;

	Node *r;
	ifstream fin("BSTinputFile.txt");
	int val;
	fin>>val;
	createBSTreadingFilePreOrder(INT_MIN, INT_MAX, val, r, fin);
	preorder(r);*/

	Node *root = NULL;
	insert(root, 4);
	insert(root, 2);
	insert(root, 6);
	insert(root, 1);
	insert(root, 3);
	insert(root, 5);
	insert(root, 7);
	insert(root, 8);
	insert(root, 9);

	preorder(root);

	cout << endl << depth(root) << endl;

	Node* c = commonAncestorBT(root, 7, 9);
	cout << "Common ancestor: " << c->data << endl;

	Node* t = commonAncestorBST(root, 7, 8);
	if(t) cout << "Common ancestor: " << t->data << endl;
	else cout << "No common ancestor" << endl;

	cout << howManyFound(root, 0, 7) << endl;

	everyPath(root, 1);

	cout << Ceil(root, 2.5) << endl;

	/*Node *ptr;
	Node *parent;
	int found = 0;
	Node * s = search(root, 8, ptr, parent, found);
	cout << endl << found << endl;
	if(found) cout << ptr->data << endl;
	else cout << "parent ->" << parent->data << endl;*/
}

