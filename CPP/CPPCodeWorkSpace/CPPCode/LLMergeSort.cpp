#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node * next;
	Node(int v):data(v), next(NULL){}
};

void addBeg(Node*& head, int val)
{
	Node* n = new Node(val);
	if(head==NULL) 
		head = n;
	else 
	{
		n->next = head;
		head = n;
	}
}

void printList(Node* head)
{
	while(head!=NULL){
		cout << head->data; 
		head = head->next;
		if(head) cout << "->";
	}
	cout << endl;
}

void splitList(Node* head, Node*& mid)
{
	if(head==NULL) return;
	if(head->next==NULL) return;

	Node* slow = head;
	Node* fast = head->next;

	while(fast->next)
	{
		fast = fast->next;
		if(fast->next)
		{
			fast = fast->next;
			slow = slow->next;
		}
	}

	mid = slow->next;
	slow->next = NULL;
}

Node* mergeTwoSortedList(Node* n1, Node* n2)
{
	if(n1==NULL) return n2;
	if(n2==NULL) return n1;

	Node* h;

	if(n1->data < n2->data){
		h = n1;
		h->next = mergeTwoSortedList(n1->next, n2);
	}
	else{
		h = n2;
		h->next = mergeTwoSortedList(n1, n2->next);
	}

	return h;
}

void mergeSort(Node*& head)
{
	if(head==NULL || head->next==NULL)
		return;
	
	Node* mid = NULL;
	splitList(head, mid);

	mergeSort(head);
	mergeSort(mid);

	head = mergeTwoSortedList(head, mid);
}

int main()
{
	Node * head = NULL;	
	addBeg(head, 5); 
	addBeg(head, 6); 
	addBeg(head, 3); 
	addBeg(head, 4);
	addBeg(head, 1);
	addBeg(head, 2);
	//addBeg(head, 7); 
	printList(head);

	mergeSort(head);
	cout << endl;
	printList(head);

	return 0;
}