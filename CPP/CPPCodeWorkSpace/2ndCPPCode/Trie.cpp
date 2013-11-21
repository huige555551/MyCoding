#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Node{
public:
	char value;
	unordered_map<char, Node*> children;
	vector<int> index;

	Node(char ch): value(ch){}

	//same as suffix tree
	void insert(string str, int i){
		if(str.empty()) return;

		this->index.push_back(i);

		Node* child;
		if(children.find(str[0])==children.end()){
			child = new Node(str[0]);
			children[str[0]] = child;
		}else{
			child = children[str[0]];
		}

		child->insert(str.substr(1), i);
	}

	vector<int> findIndex(string str){
		if(str.empty()) return index;

		if(children.find(str[0])!=children.end()){
			return children[str[0]]->findIndex(str.substr(1));
		}
		
		return index;
	}
};

class Trie{
public:
	Node* root;
	vector<string> strList;

	Trie(vector<string> strList):root(new Node(' ')), strList(strList)
	{
		//root = new Node(' ');

		for(int i=0; i<strList.size(); i++){
			root->insert(strList[i], i);
		}
	}
	
	vector<string> findWords(string str){
		vector<string> returnList;
		vector<int> list = root->findIndex(str);

		for(int i=0; i<list.size() && i < 5; i++){
			returnList.push_back(strList[list[i]]);
		}
		return returnList;
	}
};

void printTreeLevelOrder(vector<Node*> v){
	if(v.empty()) return;

	vector<Node*> nv;
	for(int i=0; i<v.size(); i++){
		cout << v[i]->value << " ";
		for(auto j=v[i]->children.begin(); j!=v[i]->children.end(); j++){
			nv.push_back(j->second);
		}
	}
	cout << endl;
	printTreeLevelOrder(nv);
}

void printStrings(vector<string> strings){
	for(int i=0; i<strings.size(); i++){
		cout << strings[i] << endl;
	}
}

int main(){
	string str[] = {"an", "ant", "all", "allot", "alloy", "aloe", "are", "ate", "be"};
	vector<string> strList(str, str+9);

	Trie t(strList);
	//t.createTrie();
	
	vector<Node*> v;
	v.push_back(t.root);
	printTreeLevelOrder(v);

	vector<string> strings = t.findWords("b");
	printStrings(strings);

	return 0;
}