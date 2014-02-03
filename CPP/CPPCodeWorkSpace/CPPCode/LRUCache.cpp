#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

template <class K, class T>
class CacheNode {
public:
	K key;
	T data;
	CacheNode* prev;
	CacheNode* next;

	CacheNode(K key): key(key), prev(NULL), next(NULL){}
};

template <class K, class T>
class Cache{
public:
	unordered_map<K, CacheNode<K, T>*> hashMap;
	CacheNode<K, T>* head, *tail;
	static const int maxSize = 4;
	
	T getReference(K key)
	{
		if(hashMap.find(key) == hashMap.end())
		{
			hashMap[key] = putInQueue(key);
			return hashMap[key]->data;
		}
		else 
		{
			CacheNode<K, T>* node = hashMap[key];
			rearrangeQueue(node);
			return node->data;
		}
	}

	CacheNode<K, T>* putInQueue(K key)
	{
		//if cache is full 
		if(hashMap.size() >= maxSize){
			//erase the LRU key from hash
			hashMap.erase(tail->key);

			//delete the tail node
			tail = tail->prev;
			delete tail->next;
			tail->next = NULL;
		}

		CacheNode<K, T>* newNode = new CacheNode<K, T>(key);

		if(hashMap.size()==0){
			tail = newNode;	
		}
		else{
			newNode->next = head;
			head->prev = newNode;
		}

		head = newNode;

		return newNode;
	}

	void rearrangeQueue(CacheNode<K, T>* node)
	{
		CacheNode<K, T> *t1, *t2;

		if(node == tail && node == head)
			return;
		else if(node == tail){
			tail = node -> prev;
		}

		t1 = node->prev;
		t2 = node->next;
		if(t1) t1->next = t2;
		if(t2) t2->prev = t1;

		node->next = head;
		node->prev = NULL;
		head = node;
	}

};


int main()
{
	Cache<int, string> lru;
	
	lru.getReference(1);
	lru.getReference(2);
	lru.getReference(3);
	lru.getReference(4);
	lru.getReference(1);
	lru.getReference(5);
	lru.getReference(3);
	lru.getReference(1);
	lru.getReference(2);

	return 0;
}