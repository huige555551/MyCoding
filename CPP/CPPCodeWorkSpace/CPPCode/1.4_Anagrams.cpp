#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool anagrams(string& s, string& t)
{
	if(s.size() != t.size()) return false;
	if(s.size()==0) return true;

	vector<int> letters(256, 0);

	int num_unique = 0;
	for(int i=0; i<s.size(); i++){
		if(letters[s[i]]==0) num_unique++;
		letters[s[i]]++;	
	}

	int num_completed = 0;
	for(int i=0; i<t.size(); i++){
		letters[t[i]]--;

		if(letters[t[i]] < 0) return false;
		if(letters[t[i]]==0) num_completed++;

		if(num_unique == num_completed){
			return (i==t.size()-1);	
		}
	}

	return false;
}

bool anagrams2(string s, string t)
{
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());

	return !(s.compare(t));
}

void main()
{
	string s, t;

	while(cin >> s >> t){
		cout << anagrams(s, t) << endl;
		cout << anagrams2(s, t) << endl;
	}
}