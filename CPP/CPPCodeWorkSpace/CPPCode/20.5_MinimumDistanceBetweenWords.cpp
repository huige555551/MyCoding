#include <iostream>
#include <utility>
#include <sstream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

#define MAX INT_MAX
#define SMALLER(A, B) A<B?A:B

typedef unordered_map<string, vector<int>> wordmap;
wordmap wm;

void coutWords(string str)
{
	string delimiters = " ,;.[]()";
	vector<string> v;
	size_t next=-1;
	size_t current;
	int word_pos=0;

	do{
		current = next + 1;
		next = str.find_first_of(delimiters, current);
		string t = str.substr(current, next - current);
		transform(t.begin(), t.end(), t.begin(), tolower);
		if(!t.empty()) {
			wm[t].push_back(word_pos);
			v.push_back(t);
			word_pos++;
		}
	}while(next!=string::npos);

	for(auto it=wm.begin(); it!=wm.end(); it++){
		cout << it->first << "->";
		for(auto it2=wm[it->first].begin(); it2!=wm[it->first].end(); it2++){
			cout << *it2 << " ";
		}
		cout << endl;
	}

}

void swap(string& str1, string& str2)
{
	string temp = str1;
	str1 = str2;
	str2 = temp;
}

int modBinarySearch(int num, const vector<int>& vec)
{
	int left=0;
	int right=vec.size()-1;
	
	int mid = 0;
	int prev = 0; 
	int after=0;
	int d1, d2;

	while(left <= right) 
	{
		mid = (left+right)/2;

		if(num == vec[mid]) 
			return 0;

		//search at the left side
		else if(num < vec[mid]){

			right = mid-1;	

			//at the conrner
			if(mid<=0) {
				return vec[mid] - num;
			}
			//if between mid and mid-1
			else if(num > vec[right]){
				d1 = num - vec[right];
				d2 = vec[mid] - num;
				return SMALLER(d1, d2); //<d2?d1:d2;
			}
			
		}
		//search at the right side
		else {
			left = mid + 1;

			//at the conrner
			if(mid>=vec.size()-1) {
				return num - vec[mid];
			}
			//if between mid and mid+1
			else if(num < vec[left]) {
				d1 = num - vec[mid];
				d2 = vec[left] - num;
				return SMALLER(d1, d2);
			}
			
		}
	}

	return -1;
}

int searchMinDist(string str1, string str2)
{
	if(wm.count(str1)==0 || wm.count(str2)==0) return -1;

	if(wm[str1].size() < wm[str2].size()) swap(str1, str2);
	
	int mini = MAX;
	for(auto it2 = wm[str2].begin(); it2!=wm[str2].end(); it2++){
		int dist = modBinarySearch(*it2, wm[str1]);
		if(dist < mini) {
			mini = dist;
			cout << *it2 << " " << mini << endl;
		}
	}

	return mini;
}

void main()
{
	string str = "The first constructor specifies a copy of the sequence controlled by right. The second constructor specifies an empty controlled sequence. The third constructor inserts the sequence of element values [first, last). The fourth constructor specifies a copy of the sequence by moving right. All constructors also initialize several stored values. For the copy constructor, the values are obtained from right. Otherwise: the minimum number of buckets is the argument nbuckets, if present; otherwise it is a default value described here as the implementation-defined value N0. the hash function object is the argument hfn, if present; otherwise it is Hash(). the comparison function object is the argument comp, if present; otherwise it is Pred(). the allocator object is the argument al, if present; otherwise, it is Alloc().";

	coutWords(str);

	string str1, str2;

	while(cin >> str1 >> str2){
		//cout << str1 << " " <<  str2 << endl;
		cout << searchMinDist(str1, str2) << endl;
	}

	cout << MAX;
}