#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void first_method(string str, string delim)
{
	int posCurr = 0;
	int posFind = str.find_first_of(delim, posCurr);

	while( posFind != string::npos){
		string temp = str.substr(posCurr, posFind-posCurr);
		posCurr = posFind + 1;
		posFind = str.find_first_of(delim, posCurr);

		if(temp.length()) cout << temp << endl;
	}
}

void second_method(string str, char ch)
{
	istringstream strStrm(str);
	string temp = "";
	while(getline(strStrm, temp, ch)){
		cout << temp << endl;
	}
}

int main()
{
	string str("Please, parse me; I want you to pierce me by *start ,comma ;semicolon.");
	string delim(" ,.*;");

	first_method(str, delim);
	second_method(str, ' ');
	return 0;
}
