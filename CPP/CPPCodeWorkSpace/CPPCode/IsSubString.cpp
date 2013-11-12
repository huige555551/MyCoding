#include <iostream>
using namespace std;

bool func(char* input, char* pattern)
{
	if(*pattern == 0) return true;
	if(*input == 0) return false;	

	if(*input == *pattern){
		return func(++input, ++pattern);	
	}
	else{
		return func(++input, pattern);
	}
}

void main()
{
	cout << func("Richarson", "Rich") << endl;
}