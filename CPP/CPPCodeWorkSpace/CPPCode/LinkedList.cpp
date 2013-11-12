#include <iostream>
#include <unordered_map>
using namespace std;

class Node
{
public:
	int data;
	Node * next;
};

Node* newNode(int val)
{
	Node* n = new Node();
	n->data = val;
	n->next = NULL;
	return n;
}
void addBeg(Node*& head, int val)
{
	Node * n = newNode(val);

	if(head==NULL) head = n;
	else
	{
		n->next = head;
		head = n;
	}

}
void printList(Node* head)
{
	while(head!=NULL){
		cout << head->data << "->";
		head = head->next;
	}
	cout << endl;
}

Node* reverse(Node* cur, Node * prev=NULL)
{
	if(cur==NULL) return NULL;

	if(cur->next==NULL) {
		cur->next = prev;
		return cur;
	}

	Node* head = reverse(cur->next, cur);
	cur->next = prev;

	return head;
}

Node* mergeSortedList(Node* head1, Node* head2)
{
	if(head1==NULL) return head2;
	if(head2==NULL) return head1;

	if(head1->data <= head2->data){		
		head1->next = mergeSortedList(head1->next, head2);
		return head1;
	}
	else{		
		head2->next = mergeSortedList(head1, head2->next);
		return head2;
	}	
}

Node* mergeSortedList2(Node* head1, Node* head2)
{
	Node* final = NULL;
	Node* head = NULL;

	if(head1==NULL) return head2;
	if(head2==NULL) return head1;

	if(head1->data <= head2->data){
		head = head1;
		head1 = head1->next;
	}
	else{ 
		head = head2;
		head2 = head2->next;
	}

	final = head;
	while(head1!=NULL && head2!=NULL)
	{
		if(head1->data <= head2->data){
			final->next = head1;
			head1 = head1->next;
		}
		else{
			final->next = head2;
			head2 = head2->next;
		}
		final = final->next;
	}

	if(head1!=NULL) final->next = head1;
	else final->next = head2;

	return head;
}

void removeDuplicate(Node* root)
{
	unordered_map<int, bool> hashTable;
	Node* prev = NULL;

	while(root)
	{
		int data = root->data;
		if(hashTable.find(data) == hashTable.end()){
			hashTable[data] = true;
			prev = root;			
		}else{
			prev->next = root->next;
		}

		root = root->next;		
	}
}

void deleteANode(Node* ptr)
{
	if(!ptr) return;

	Node* temp = ptr->next;
	ptr->data = temp->data;
	ptr->next = temp->next;
	delete temp;
}

Node* addLists(Node* l1, Node* l2, int carry=0)
{
	if(l1==NULL && l2==NULL) return NULL;

	Node* root = new Node();
	root->next = NULL;

	int val = carry;

	if(l1){
		val += l1->data;
		l1 = l1->next;
	}
	if(l2){
		val += l2->data;
		l2 = l2->next;
	}
	
	root->data = val%10;
	root->next = addLists(l1, l2, val/10);

	return root;
}

int main()
{
	Node * head1 = NULL;	
	addBeg(head1, 7); 
	addBeg(head1, 5); 
	addBeg(head1, 3); 
	addBeg(head1, 3);
	addBeg(head1, 1);
	addBeg(head1, 1);
	printList(head1);

	Node * head2 = NULL;	
	addBeg(head2, 8); 
	addBeg(head2, 6); 
	addBeg(head2, 4); 
	addBeg(head2, 2);
	printList(head2);

	Node* sum = addLists(head1, head2);
	printList(sum);

	//Node* h = mergeSortedList(head1, head2);
	//printList(h);

	Node* h = mergeSortedList2(head1, head2);
	printList(h);

	head1 = reverse(head1);
	printList(head1);

	removeDuplicate(head1);
	printList(head1);

	deleteANode(head1->next);
	printList(head1);

	int a;
	cin>>a;

	return 0;
}