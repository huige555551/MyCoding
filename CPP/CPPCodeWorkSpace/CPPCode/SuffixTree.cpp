#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <memory>
using namespace std;

class SuffixTreeNode
{
	char value;
	unordered_map<char, SuffixTreeNode*> children;
	vector<int> indexes;

public:
	void insertString(string s, int index)
	{
		if(s.empty()) return;
		if(index < 0) return;

		indexes.push_back(index);		
		
		SuffixTreeNode* child;

		if(children.count(s[0])>0){
			child = children[s[0]];	
		}
		else {
			child = new	SuffixTreeNode();
			child->value = s[0];
			children[s[0]] = child;
		}

		string remainder = s.substr(1);
		child->insertString(remainder, index);
	}

	vector<int> getIndexes(string str)
	{
		if(str.size()==0) 
			return indexes;
		
		char first = str[0];
		if(children.count(first)>0)
		{
			string remainder = str.substr(1);
			SuffixTreeNode* t = children[first];
			return t->getIndexes(remainder);
		}
		else{
			vector<int> emp;
			return emp;
		}
	}

};

class SuffixTree
{
	SuffixTreeNode* root;
	//unique_ptr<SuffixTreeNode> root;

public:
	SuffixTree(string str) //: root(new SuffixTreeNode())
	{
		root = new SuffixTreeNode();

		for(int i=0; i<str.size(); i++){
			string suffix = str.substr(i);
			root->insertString(suffix, i);
		}
	}

	vector<int> getIndexes(string str)
	{
		return root->getIndexes(str);
	}
};


int main()
{
	string testString = "mississippi";
	SuffixTree tree(testString);

	string stringList[] = {"is", "sip", "hi", "sis"};

	for(int i=0; i<4; i++)
	{
		vector<int> list = tree.getIndexes(stringList[i]);

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