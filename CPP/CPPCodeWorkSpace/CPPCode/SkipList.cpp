#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
	int data;
	vector<Node*> next;	//next pointer for each level

	Node(): data(0), next(0){}
	Node(int d, int level): data(d), next(level, NULL) {}
};

class SkipList{
public:
	Node *head;
	int maxLevel;

	SkipList(int level): maxLevel(level)
	{
		head = new Node(INT_MIN, maxLevel);

		Node* sentinel = new Node(INT_MAX, maxLevel);
		for(int i=0; i<maxLevel; i++)
			head->next[i] = sentinel;
	}

	void insert(int value)
	{
		int level = rand()/(RAND_MAX+1.0)* (maxLevel) + 1;

		Node* newNode = new Node(value, level);
		Node* curr = head;
		Node* prev = NULL;

		for(int i=level-1; i>=0; i--) {

			while(curr->data < value){
				prev = curr;
				curr = curr->next[i];
			}
			prev->next[i] = newNode;
			newNode->next[i] = curr;

			curr = prev;
		}
	}

	Node* find(int value)
	{
		Node* curr = head;
		Node* prev = NULL;

		for(int i=maxLevel-1; i>=0; i--) {

			if(curr->data == value) return curr;

			while(curr->data <= value){
				prev = curr;
				curr = curr->next[i];
			}
			curr = prev;
		}

		if(curr->data == value) return curr;
		
		return NULL;
	}

	bool remove(int value)
	{
		Node* curr = head;
		Node* prev = NULL;
		bool found = false;
		Node* temp = NULL;

		for(int i=maxLevel-1; i>=0; i--) {

			while(curr->data <= value){
				prev = curr;
				curr = curr->next[i];

				if(curr->data == value){
					prev->next[i] = curr->next[i];
					found = true;
					temp = curr;
					break;
				}
			}
			curr = prev;
		}

		if(temp && found) {
			delete temp;
		}
		
		return found;
	}

};


int main()
{
	SkipList s(4);
	s.insert(100);
	s.insert(10);
	s.insert(50);
	s.insert(70);
	s.insert(30);

	cout << (!s.find(10)?0:1) << std::endl;
	cout << (!s.find(20)?0:1) << std::endl;
	cout << (!s.find(30)?0:1) << std::endl;
	cout << (!s.find(40)?0:1) << std::endl;
	cout << (!s.find(50)?0:1) << std::endl;
	cout << (!s.find(60)?0:1) << std::endl;
	cout << (!s.find(70)?0:1) << std::endl;
	cout << (!s.find(80)?0:1) << std::endl;
	cout << (!s.find(90)?0:1) << std::endl;
	cout << (!s.find(100)?0:1) << std::endl;
	cout << (!s.find(110)?0:1) << std::endl;
	
	s.remove(70);

	cout << (!s.find(70)?0:1) << std::endl;

	return 0;
}



//http://igoro.com/archive/skip-lists-are-fascinating/
//https://www.cs.umd.edu/users/meesh/420/Notes/MountNotes/lecture11-skiplist.pdf