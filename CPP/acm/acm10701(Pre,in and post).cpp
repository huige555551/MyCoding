#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char preorder[100],inorder[100];
int pre_index;

struct node{
	char c;
	node *left;
	node *right;
};

node * build_tree(int left,int right)
{
	char ch;
	int i;

	if(left > right) return NULL;

	ch = preorder[pre_index];

	for(i=0; inorder[i] != ch; i++);

	pre_index++;

	node *t= new node;

	t->c = inorder[i];
	t->left = build_tree(left,i-1);
	t->right = build_tree(i+1,right);

	return t;
}

void post_order(node *root)
{
	if(root->left) post_order(root->left);
	if(root->right) post_order(root->right);

	printf("%c",root->c);
}

void free_tree(node *root)
{
	if(root->left) free_tree(root->left);
	if(root->right) free_tree(root->right);

	delete root;
}

void main()
{
	int n,testcase;
	node *root;

	freopen("in.txt","r",stdin);

	scanf("%d",&testcase);

	while(testcase)
	{
		scanf("%d%s%s",&n,preorder,inorder);

		pre_index=0;

		root = build_tree(0,(strlen(inorder)-1));

		post_order(root);

		printf("\n");

		free_tree(root);

		testcase--;
	}	
}