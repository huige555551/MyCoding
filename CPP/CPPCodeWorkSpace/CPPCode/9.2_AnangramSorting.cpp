#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class sortAnagram 
{
	string sortCharInString(const string& str)
	{
		vector<char> charVec(str.begin(), str.end());
		sort(charVec.begin(), charVec.end());
		string newStr(charVec.begin(), charVec.end());
		return newStr;
	}

public:
	bool operator()(const string& s1, const string& s2){
		string p1 = sortCharInString(s1);
		string p2 = sortCharInString(s2);

		//anagrams are sorted 
		if(p1.compare(p2)==0) {
			if(s1 < s2) return true;
			else return false;
		}

		return p1 < p2;
	}
};

void main()
{
	string strArray[] = {"coal", "apple", "alpel", "ape", "cola", "aocl", "pea", "a", "bc", "cb", "zac", "caz"};
	vector<string> vecStr(strArray, strArray+12);

	sortAnagram sortAnagramObj;
	sort(vecStr.begin(), vecStr.end(), sortAnagramObj);
	for(int i=0; i<vecStr.size(); i++) cout << vecStr[i] << " ";
}