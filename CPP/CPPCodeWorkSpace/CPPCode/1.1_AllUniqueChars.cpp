#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool alluniquechar(char* str)
{
	vector<bool> charset(256, false);
	
	while(*str!='\0'){
		if(charset[*str]) return false;
		charset[*str] = true;
		str++;
	}

	return true;
}

bool alluniquesmall(string str){
	int check = 0;

	for(int i=0; i<str.length(); i++){
		int letter = str[i]-'a';
		if(check & (1<<letter)) return false;
		check = check | (1<<letter);
	}

	return true;
}

void main()
{
	cout << alluniquechar("abcda") << endl;
	cout << alluniquesmall("abcd") << endl;
}