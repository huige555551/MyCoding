#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool alluniquechar(const char* str)
{
	vector<bool> charset(256, false);
	
	while(*str!='\0'){
		if(charset[*str]) return false;
		charset[*str] = true;
		str++;
	}

	return true;
}

bool alluniquesmall(string str)
{
	int check = 0;

	for(int i=0; i<(int)str.length(); i++){
		int letter = str[i]-'a';
		if(check & (1<<letter)) return false;
		check = check | (1<<letter);
	}

	return true;
}

int main()
{
	cout << alluniquechar("abcda") << endl;
	cout << alluniquesmall("abcda") << endl;
    return 0;
}
