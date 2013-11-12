#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	Node * next;
};

Node * newNode(int num)
{
	Node * temp;

	//temp = ( Node *)malloc(sizeof( Node));
	temp = new Node;
	temp->data=num;	
	temp->next=NULL;

	return temp;
}

//void addBeg(Node ** HeadRef, int num)
void addBeg(Node *& HeadRef, int num)
{
	Node * temp;
	//Node * Head = * HeadRef;
	Node * Head = HeadRef;

	temp = newNode(num);
	
	if(Head==NULL)	
	{
		//*HeadRef = temp;		
		HeadRef = temp;		
	}
	else
	{
		temp->next=Head;
		//*HeadRef=temp;
		HeadRef=temp;
	}
}

void show(Node * Head)
{
	while(Head!=NULL)
	{
		printf("%d",Head->data);
		Head=Head->next;
	}
	printf("\n");
}

Node * reverse(Node *curr, Node * prev = NULL)
{
	if(curr->next==NULL){
		curr->next = prev;
		return curr;
	}
	
	Node* head = reverse(curr->next, curr);
	curr->next = prev;

	return head;
}

Node * reverse2(Node * ptr)
{
	Node * temp;
	Node * prev=NULL;

	while(ptr != NULL) 
	{
		temp = ptr->next;
		ptr->next=prev;
		prev=ptr;
		ptr=temp;
	}

	return prev;

}

void sort( Node *Head)
{
	Node * first;
	Node * second;

	first = Head;	
	while(first!=NULL)
	{
		second = first->next;

		while(second!=NULL)
		{
			if(first->data > second->data)
			{
				int temp = first->data;
				first->data = second->data;
				second->data = temp;
			}
			second=second->next;
		}

		first=first->next;
	}

}

Node* copy(Node* ptr)
{
	if(ptr==NULL) {
		return NULL;
	}

	Node* temp = new Node;		
	temp->data=ptr->data;
	temp->next = copy(ptr->next);

	return temp;
	
}

void copy2(Node * ptr, Node*& newHead)
{
	if(ptr==NULL) return;
	
	newHead = new Node;
	newHead->data = ptr->data;
	newHead->next = NULL;

	copy2(ptr->next, newHead->next);
}

void main()
{
	Node * Head = NULL;
	Node * H2 = NULL;

	//addBeg(&Head,1);
	addBeg(Head,1);	
	addBeg(Head,2);	
	addBeg(Head,3);	
	addBeg(Head,4);
	show(Head);

	Head = reverse(Head);
	show(Head);

	Head = reverse2(Head);
	show(Head);

	sort(Head);
	show(Head);	

	H2 = copy(Head);
	show(H2);

	Node * H3;

	copy2(Head, H3);
	show(H3);

	getchar();
}

