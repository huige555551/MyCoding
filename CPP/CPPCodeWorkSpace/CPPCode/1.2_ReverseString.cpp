#include <iostream>
#include <string>
using namespace std;

void reverseCstyle(char* str)
{
	char* temp = str;

	if(!str) return;
	
	while(*temp) temp++;
	temp--;

	while(str < temp){
		char t = *str;
		*str = *temp;
		*temp = t;

		str++;
		temp--;
	}	
}

void reverseString(string& str)
{
	int i = 0; 
	int j = str.size()-1;

	while(i<j)
	{
		char temp = str[i];
		str[i++] = str[j];
		str[j--] = temp;
	}
}

void main()
{
	char str[100];
	
	while(scanf("%s", str)!=EOF)
	{
		reverseCstyle(str);
		cout << str << endl;

		string s(str);
		reverseString(s);
		cout << s << endl;
	}



	//char str[] = {'a','b','c','d','\0'};
	//char str2[] = {'\0'};
	//cout << str2 << endl;
	//reverseCstyle(str2);
	//cout << str2 << endl;
}