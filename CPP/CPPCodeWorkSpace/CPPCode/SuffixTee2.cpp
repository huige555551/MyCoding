#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Node{
public:
	char ch;
	unordered_map<char, Node*> children;
	vector<int> indexes; //store the indexes of the substring from where it starts
};

void insertInSuffixTree(Node* node, string str, int index){
	
	if(index < 0) return;
	node->indexes.push_back(index);

	if(str.empty()) return;

	char ch = str[0];
	Node * child;

	if(node->children.count(ch) > 0){
		child = node->children[ch];
	}else{
		child = new Node();
		child->ch = ch;
		node->children[ch] = child;
	}

	string remainder = str.substr(1);

	insertInSuffixTree(child, remainder, index);
}

vector<int> getIndexesFromSuffixTree(Node* root, string str){

	if(str.empty()){
		return root->indexes;
	}

	char ch = str[0];
	if(root->children.count(ch)>0){
		return getIndexesFromSuffixTree(root->children[ch], str.substr(1));
	}
	else{
		return vector<int>();
	}
}

int main()
{
	string testString = "mississippi";
	
	Node * root = new  Node();
	root->ch = '@';
	
	//insert all substring in suffix tree
	for(int i=0; i<testString.size(); i++){
		string str = testString.substr(i);
		insertInSuffixTree(root, str, i);
	}

	string stringList[] = {"is", "sip", "hi", "sis"};
	for(int i=0; i<4; i++)
	{
		vector<int> list = getIndexesFromSuffixTree(root, stringList[i]);

		if(list.empty()) 
			cout << stringList[i] << ": Not existed";
		else {
			cout << stringList[i] << ": "; 
			for(int j=0; j<list.size(); j++) cout << list[j] << " ";
		}
		cout << endl;
	}

	return 1;
}