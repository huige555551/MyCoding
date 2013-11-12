#include <iostream>
#include <utility>
#include <sstream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

typedef unordered_map<string, int> wordmap;
typedef unordered_map<string, int>::iterator wmitrtype;
wordmap wm;

bool comparator(string s1, string s2)
{
	if(wm[s1]>wm[s2])
		return true;
	else if(wm[s1]==wm[s2]){
		return s1<s2;
	}
	else return false;
}

struct comparemap
{
public:
	bool operator()(string s1, string s2){
		if(wm[s1]>wm[s2])
			return true;
		else if(wm[s1]==wm[s2]){
			return s1<s2;
		}
		else return false;
	}
} comp;

void coutWords(string str)
{
	string delimiters = " ,;.[]()";
	vector<string> v;
	size_t next=-1;
	size_t current;

	do{
		current = next + 1;
		next = str.find_first_of(delimiters, current);
		string t = str.substr(current, next - current);
		transform(t.begin(), t.end(), t.begin(), tolower);
		if(!t.empty()) {
			cout << t; //<< endl;
			wm[t] = wm[t]+1;
			v.push_back(t);
		}
	}while(next!=string::npos);


	for(wmitrtype itr=wm.begin(); itr!=wm.end(); itr++)
	{
		cout << itr->first << "->" << itr->second << endl;
	}

	set<string> s(v.begin(), v.end());
	v.assign(s.begin(), s.end());
	
	sort(v.begin(), v.end(), comp);
	//sort(v.begin(), v.end(), comparator);
	
	cout << endl << endl;
	for(auto it=v.begin(); it!=v.end(); it++)
		cout << *it << "->" << wm[*it] << endl;	

	cout << "the exist? " << wm.count("the") << endl;
	auto it = wm.find("te");
	if(it!=wm.end())
	cout << "find the : " << it->second << endl;
}


void main()
{
	coutWords("The first constructor specifies a copy of the sequence controlled by right. The second constructor specifies an empty controlled sequence. The third constructor inserts the sequence of element values [first, last). The fourth constructor specifies a copy of the sequence by moving right. All constructors also initialize several stored values. For the copy constructor, the values are obtained from right. Otherwise: the minimum number of buckets is the argument nbuckets, if present; otherwise it is a default value described here as the implementation-defined value N0. the hash function object is the argument hfn, if present; otherwise it is Hash(). the comparison function object is the argument comp, if present; otherwise it is Pred(). the allocator object is the argument al, if present; otherwise, it is Alloc().");

}