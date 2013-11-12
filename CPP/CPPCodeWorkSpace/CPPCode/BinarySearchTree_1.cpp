#include < stdio.h >
#include < stdlib.h >
#include < conio.h>
#include < iostream >
#include < stack >
#include < queue >
#include < fstream >

using namespace std;

struct node
{
	int data;
	node * left;
	node * right;
};

void search(struct node ** root, int num, struct node ** parent, struct node ** ptr, int *found)
{
	node * temp = *root;
	*parent = *ptr = NULL;
	*found = 0;

	while(temp!=NULL)
	{
		if(num==temp->data)
		{
			*ptr = temp;
			*found = 1;
			return;
		}
		else if(num < temp->data)
		{
			*parent = temp;
			temp = temp->left;
		}
		else 
		{
			*parent = temp;
			temp = temp->right;
		}
	}

}

void insert(struct node **ptr, int num)
{
	if(*ptr==NULL)
	{
		*ptr = new node(); //*ptr = malloc(struct node); 
		(*ptr)->data = num;
		(*ptr)->left = NULL;
		(*ptr)->right = NULL;
	}	
	else
	{
		if(num < (*ptr)->data)
			insert(&((*ptr)->left), num);
		else
			insert(&((*ptr)->right), num);
	}
}

void insert2(node ** root, int num)
{
	struct node * parent;
	struct node * ptr;
	int found = 0;

	ptr = *root;

	/*while(ptr!=NULL && !found)
	{
		parent = ptr;

		if(num == ptr->data)
			found = 1;
		if(num < ptr->data)
			ptr=ptr->left;
		else
			ptr=ptr->right;
	}*/
	search(root, num, &parent, &ptr, &found);

	if(!found)
	{
		ptr = new node;
		ptr->data = num;
		ptr->left = ptr->right = NULL;

		if(*root==NULL)
			*root = ptr;
		else
		{
			if(num < parent->data)
				parent->left = ptr;
			else
				parent->right = ptr;
		}
	}

}

void deleteNode(struct node ** root, int num)
{
		int found = 0;
		struct node * parent, *x, *xsucc;

		if(*root==NULL)
		{
			printf("Tree is empty\n");
			return;
		}

		parent = x = NULL;

		search(root,num,&parent,&x,&found);

		if(!found)
		{
			printf("Data to be deleted, not found!\n");
			return;
		}

		//two children
		if(x->left!=NULL && x->right!=NULL)
		{
			parent=x;
			xsucc = x->right;

			while(xsucc->left!=NULL)
			{
				parent = xsucc;
				xsucc = xsucc->left;
			}

			x->data = xsucc->data;
			x=xsucc;
		}

		//no child
		if(x->left==NULL && x->right==NULL)
		{
			if(parent->left==x)
				parent->left=NULL;
			else parent->right=NULL;

			delete x;
			return;
		}

		//right child only
		if(x->left == NULL && x->right!=NULL)
		{
			if(parent->left==x)
				parent->left=x->right;
			else
				parent->right=x->right;

			delete x;
			return;
		}

		//left child only
		if(x->left != NULL && x->right==NULL)
		{
			if(parent->left==x)
				parent->left=x->left;
			else
				parent->right=x->left;

			delete x;
			return;
		}

		return;
}

//Start of Recrusive Traversal
void inOrder(struct node *ptr)
{
	if(ptr==NULL) return;

	inOrder(ptr->left);
	printf("%d",ptr->data);
	inOrder(ptr->right);
}

void preOrder(struct node * ptr)
{
	if(ptr==NULL) return;
	
	printf("%d",ptr->data);
	preOrder(ptr->left);
	preOrder(ptr->right);

}

void postOrder(struct node * ptr)
{
	if(ptr==NULL) return;
	
	postOrder(ptr->left);
	postOrder(ptr->right);
	printf("%d",ptr->data);

}
//End of Recrusive Traversal

void preOrderNonRecursion(struct node *root)
{
	stack<struct node *> stack;
	stack.push(root);

	while(!stack.empty())
	{
		root=stack.top();
		stack.pop();

		if(root!=NULL)
		{
			printf("%d",root->data);
			stack.push(root->right);
			stack.push(root->left);
		}
	}
}

void inOrderNonRecursion(struct node *root)
{
	struct node * ptr = root;
	//stack<struct node *> s;
	struct node * sa[10];
	int top = -1;

	//while(!s.empty() || ptr!=NULL)
	while( top!=-1 || ptr!=NULL)
	{
		if(ptr!=NULL)
		{
			//s.push(ptr);    
			sa[++top]=ptr;
			ptr = ptr->left;
		}
		else
		{
			ptr = sa[top];//s.top();
			top--;
			//s.pop();
			printf("%d",ptr->data);

			ptr=ptr->right;
		}

	}
}

//1 pass - most efficient
void postOrder1(struct node *root)
{
	struct node * node = root;
	stack<struct node*> stack;

	while (node != NULL || !stack.empty()) 
	{
        if (node == NULL) 
		{
            while (!stack.empty() && node == stack.top()->right) 
			{
                node = stack.top(); 
				stack.pop();
                
				printf("%d",node->data);
            }
            node = stack.empty() ? NULL : stack.top()->right;
        }
        if (node != NULL) {
            stack.push(node);
            node = node->left;
        }
    }

}

//2 pass
void postOrder2(struct node * ptr)
{
	int i=0;
	stack<pair<struct node*, int>> s;
	s.push(make_pair(ptr,1));

	while (!s.empty())
	{
		pair<struct node *, int> p = s.top();
		ptr = p.first;
		i = p.second;

		s.pop();

		if(ptr)
		{
			if(i==1)
			{
				s.push(make_pair(ptr,2));
				s.push(make_pair(ptr->right,1));
				s.push(make_pair(ptr->left,1));
			}
			else if(i==2)
			{
				printf("%d",ptr->data);
			}
		}
	}
}

//conventional 3 pass - easiest
void postOrder3(struct node * ptr)
{
	int i=0;
	stack<pair<struct node*, int>> s;
	s.push(make_pair(ptr,1));

	while (!s.empty())
	{
		pair<struct node *, int> p = s.top();
		ptr = p.first;
		i = p.second;

		s.pop();

		if(ptr)
		{
			if(i==1)
			{
				s.push(make_pair(ptr,2));
				s.push(make_pair(ptr->left,1));
			}
			else if(i==2)
			{
				s.push(make_pair(ptr,3));
				s.push(make_pair(ptr->right,1));
				
			}
			else
			{
				printf("%d",ptr->data);
			}
		}
	}
}

//InOrder traversal without stack and recursion
//http://geeksforgeeks.org/?p=6358
void MorrisTraversal(struct node *root)
{
  struct node *current,*pre;
 
  if(root == NULL)
     return; 
 
  current = root;
  while(current != NULL)
  {
    if(current->left == NULL)
    {
      printf(" %d ", current->data);
      current = current->right;
    }
    else
    {
      /* Find the inorder predecessor of current */
      pre = current->left;
      while(pre->right != NULL && pre->right != current)
        pre = pre->right;
 
      /* Make current as right child of its inorder predecessor */
      if(pre->right == NULL)
      {
        pre->right = current;
        current = current->left;
      }
 
      /* Revert the changes made in if part to restore the original
        tree i.e., fix the right child of predecssor */
      else
      {
        pre->right = NULL;
        printf(" %d ",current->data);
        current = current->right;
      } /* End of if condition pre->right == NULL */
    } /* End of if condition current->left == NULL*/
  } /* End of while */
}
//End of Traversal


//Is Binary tree a BST or validation test of BST
/* Returns true if the given tree is a BST and its values are >= min and <= max. */
int isBSTUtil(struct node* node, int min, int max)
{  
  if (node==NULL)
     return 1;
 
  if (node->data < min || node->data > max)
     return 0; 
 
  /* otherwise check the subtrees recursively,
   tightening the min or max constraint */
  return
    isBSTUtil(node->left, min, node->data-1) && isBSTUtil(node->right, node->data+1, max);
} 

int isBST(struct node* node)
{
	return(isBSTUtil(node, INT_MIN, INT_MAX));
} 

bool isBSTInOrderHelper(node *p, int& prev) 
{
	if (!p) return true;
	if (isBSTInOrderHelper(p->left, prev)) 
	{
		if (p->data > prev) 
		{
			prev = p->data;
			return isBSTInOrderHelper(p->right, prev);
		} 
		else 
		{
			return false;
		}
	}
	else 
	{
		return false;
	}
}
//End of Validation Test


//Creation of BST reading in preorder style
int inputArray[] = {4,2,3,6,5,7};

void createBSTreadingPreOrder(int min,int max, node * &ptr, int val)
{
	static int index = 0;
	
	if(val<=min || val>=max)
		return;
	else
	{
		ptr = new node;
		ptr->data = val;
		ptr->left = ptr->right = NULL;

		index++;
		
		if(index < sizeof(inputArray)/sizeof(inputArray[0]))
		{
			//int nextval = inputArray[index];

			createBSTreadingPreOrder(min, val, ptr->left, inputArray[index]);
			createBSTreadingPreOrder(val, max, ptr->right, inputArray[index]);
		}
	}
}

//reference and static variable can retain their value between function call
//we have used here &val to retain the new value read from file
//alternatively we could have used static variable for it
void createBSTFromFileReadingPreOrder(int min, int max, int &val, node *& ptr, ifstream &fin)
{
	if(val<=min || val>=max)
		return;

	ptr = new node;
	ptr->data = val;
	ptr->left = ptr->right = NULL;

	if(fin>>val)
	{
		createBSTFromFileReadingPreOrder(min, ptr->data, val, ptr->left, fin);
		createBSTFromFileReadingPreOrder(ptr->data, max, val, ptr->right, fin);
	}
}

void createBSTFromFile(node *&root, ifstream &fin)
{
	int val;
	fin>>val;
	createBSTFromFileReadingPreOrder(INT_MIN, INT_MAX, val, root, fin);
}

//not final - but works for normal input
void createBSTLevelOrder(node * &root, ifstream &fin)
{
	int val;
	queue<node *> nodeQueue;
	queue<int> valueQueue;

	fin>>val;
	root = new node;
	root->data=val;
	root->left=root->right=NULL;

	nodeQueue.push(root);
	fin>>val;
	valueQueue.push(val);
	fin>>val;
	valueQueue.push(val);

	while(!valueQueue.empty())
	{
		node * ptr = nodeQueue.front(); nodeQueue.pop();
		int leftval = valueQueue.front(); valueQueue.pop();
		int rightval = valueQueue.front(); valueQueue.pop();
		
		node * leftchild = new node;
		node * rightchild = new node;
		leftchild->data = leftval;
		rightchild->data = rightval;
		leftchild->left = leftchild->right = rightchild->left = rightchild->right = NULL;

		ptr->left=leftchild;
		ptr->right=rightchild;

		nodeQueue.push(leftchild);
		nodeQueue.push(rightchild);

		if(fin>>val)
		{
			valueQueue.push(val);
			fin>>val;
			valueQueue.push(val);
		}
	}
}

int LowestCommonAncestor(node * root, int value1, int value2)
{
	node * current = root;

	while(1)
	{
		if(current->data > value1 && current->data > value2){
			current = current->left;
		}
		else if(current->data < value1 && current->data < value2){
			current = current->right;
		}
		else{
			return current->data;
		}
	}
}

void main()
{
	node * root = NULL;
	ifstream fin;

	/*fin.open("D:\\CPPCode\\BSTinputFile.txt");
	if(!fin) cout<<"error";
	createBSTFromFile(root,fin);
	fin.close();*/

	fin.open("D:\\CPPCode\\inLevelOrder.txt");
	if(!fin) cout<<"error";
	createBSTLevelOrder(root,fin);
	fin.close();

	//createBSTreadingPreOrder(INT_MIN, INT_MAX, root, inputArray[0]);

	bool isValid = isBST(root);
	cout<<(isValid?"Yes":"No");

	int a = INT_MIN;
	isValid = isBSTInOrderHelper(root,a);
	cout<<(isValid?"Yes":"No");
	
	//insert2(&root, 4);
	//insert2(&root, 2);
	//insert2(&root, 6);
	//insert2(&root, 1);
	//insert2(&root, 3);
	//insert2(&root, 5);
	//insert2(&root, 7);
	//insert2(&root, 8);


	////int found = 0;
	////node * parent, * ptr;
	////search(root,);

	////deleteNode(&root,5);
	////inOrder(root);
	////printf("\n");

	printf("\nInOrder:\n");
	inOrder(root);
	printf("\n");
	//inOrderNonRecursion(root);
	//printf("\n");
	//MorrisTraversal(root);
	//printf("\n");

	//printf("\nPreOrder:\n");
	//preOrder(root);
	//printf("\n");	
	//preOrderNonRecursion(root);  
	//printf("\n");

	//printf("\nPostOrder:\n");
	//postOrder(root);
	//printf("\n");
	//postOrder1(root);  
	//printf("\n");
	//postOrder2(root);
	//printf("\n");
	//postOrder3(root);
	//printf("\n");

	printf("\nLevelOrder:\n");
	levelOrder(root);


	int value1 = 2; 
	int value2 =3;
	cout<<"LowestCommonAncestor: "<<value1<<","<<value2<<endl;
	cout<<LowestCommonAncestor(root,value1,value2);
	

	getch();
	
}




/**

inordertraverse(node):
  stack = []
  while !empty(stack) || node != None do:
    if node != None do: // this is a normal call, recurse
      push(stack,node)
      node = node.left
    else // we're returning: pop and print the current node
      node = pop(stack)
      print node.value
      node = node.right
    endif
  endwhile

http://discuss.joelonsoftware.com/default.asp?interview.11.318495.11

void preorder(const Node* node) {
    std::stack<const Node*> stack;
    while (node != NULL || !stack.empty()) {
        if (node == NULL) {
            node = stack.top(); stack.pop();
        }
        process(node->value);
        if (node->right != NULL)
            stack.push(node->right);
        node = node->left;
    }
}

void inorder(const Node* node) {
    std::stack<const Node*> stack;
    while (node != NULL || !stack.empty()) {
        if (node == NULL) {
            node = stack.top(); stack.pop();
            process(node->value);
            node = node->right;
        }
        if (node != NULL) {
            stack.push(node);
            node = node->left;
        }
    }
}

void postorder(const Node* node) {
    std::stack<const Node*> stack;
    while (node != NULL || !stack.empty()) {
        if (node == NULL) {
            while (!stack.empty() && node == stack.top()->right) {
                node = stack.top(); stack.pop();
                process(node->value);
            }
            node = stack.empty() ? NULL : stack.top()->right;
        }
        if (node != NULL) {
            stack.push(node);
            node = node->left;
        }
    }
}

**/