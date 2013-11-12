#include <iostream>
using namespace std;

void stringFilter(char* str)
{
	int j=0; //new index for string

	for(int i=0; str[i]; i++)
	{
		if(str[i]=='b')	continue;

		if(str[i]=='a' && str[i+1]=='c'){
			i++;
			continue;
		}

		if(i!=j) str[j] = str[i]; 

		if(str[j-1]=='a' && str[j]=='c'){
			j-=2;
		}

		j++;
	}
	str[j] = 0;
}

int main()
{
	char str1[] = "ad";
    stringFilter(str1);
    cout << str1 << endl;
 
    char str2[] = "acbac";
    stringFilter(str2);
    cout << str2 << endl;
 
    char str3[] = "aaac";
    stringFilter(str3);
    cout << str3 << endl;
 
    char str4[] = "react";
    stringFilter(str4);
    cout << str4 << endl;
 
    char str5[] = "aa";
    stringFilter(str5);
    cout << str5 << endl;
 
    char str6[] = "ababaac";
    stringFilter(str6);
    cout << str6 << endl;

	char str7[] = "aacacc";
    stringFilter(str7);
    cout << str7 << endl;
	
	char str8[] = "dabcd";
    stringFilter(str8);
    cout << str8 << endl;

	return 0;
}