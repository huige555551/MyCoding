#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <string>
using namespace std;

bool myfunction (int i,int j) { return (i<j); }

struct myclass {
  bool operator() (int i,int j) { return (i<j);}
} myobject;


string sortedCharString(const string& s1){
	vector<char> tempv;
	for(int i=0; i<s1.length(); i++) tempv.push_back(s1[i]);
	sort(tempv.begin(), tempv.end());
	string newstr(tempv.begin(), tempv.end());
	return newstr;
}

class myclassStr {
public:
	bool operator() (const string& s1, const string& s2) { 
		string p1 = sortedCharString(s1);
		string p2 = sortedCharString(s2);	  
		return p1 < p2;
	}
};

int main () {
  //int myints[] = {32,71,12,45,26,80,53,33};
  //std::vector<int> myvector (myints, myints+8);               // 32 71 12 45 26 80 53 33

  // using default comparison (operator <):
  //std::sort (myvector.begin(), myvector.begin()+4);           //(12 32 45 71)26 80 53 33

  // using function as comp
  //std::sort (myvector.begin()+4, myvector.end(), myfunction); // 12 32 45 71(26 33 53 80)

  // using object as comp
  //std::sort (myvector.begin(), myvector.end(), myobject);     //(12 26 32 33 45 53 71 80)

  // print out content:
  /*std::cout << "myvector contains:";
  for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';*/

  string strArray[] = {"coal", "apple", "ape", "cola", "aocl", "pea", "a", "bc", "cb"};
  vector<string> vs(strArray, strArray+9);

  myclassStr myobjectStr;
  std::sort (vs.begin(), vs.end(), myobjectStr); 

  for (std::vector<string>::iterator it=vs.begin(); it!=vs.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}