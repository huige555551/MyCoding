#include <iostream>
#include <vector>
#include <string>
using namespace std;

string insertAt(string s, char ch, int pos)
{
	string start = s.substr(0,pos);
	string end = s.substr(pos);	
	string str = start + ch + end;
	return str;
}

vector<string> permutation(string s){
		
	if(s.empty()) {vector<string> v; v.push_back("null"); return v;}
	if(s.length()==1){
		vector<string> p;
		p.push_back(s);
		return p;
	}
	string substr = s.substr(1);
	vector<string> smaller_perm = permutation(substr);
	vector<string> new_perm;

	char ch = s[0];
	for(int i=0; i<smaller_perm.size(); i++){
		for(int j=0; j<=smaller_perm[i].size(); j++){
			string str = insertAt(smaller_perm[i], ch, j);
			new_perm.push_back(str);
		}
	}
	return new_perm;
}

void swap(char& ch1, char& ch2){
	int temp = ch1;
	ch1 = ch2;
	ch2 = temp;
}

void permutation2(string str, int p=0)
{
	if(p==str.size()) {
		cout << str << endl;
		return;
	}
	
	for(int i=p; i<str.size(); i++){		
		swap(str[p], str[i]);

		permutation2(str, p+1);

		swap(str[p], str[i]);				
	}
	
}

void main()
{
	string s = "123";
	vector<string> p = permutation(s);
	
	for(int i=0; i<p.size(); i++){
		cout << p[i] << endl; 
	}

	cout << "2nd method\n";
	permutation2(s);
}