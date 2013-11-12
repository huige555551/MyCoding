#include <string>
#include <iostream>
using namespace std;

int string2int(string str)
{
	int ans = str[0] - '0';
	for(int i=1; i<str.size(); i++)
	{
		ans *= 10;
		ans += (str[i]-'0');
	}
	return ans;
}

string int2string(int num)
{
	if(num==0) return "";

	char t = (num%10) + '0';
	string r = int2string(num/10);
	return r+t;	
}

void int2char(int num, char* str)
{
	while(num){
		*str++ = num%10 + '0';
		num = num/10;
	}
	*str = '\0';
}

string int2string2(int num)
{
	string str;

	while(num){
		char ch = num%10 + '0';
		str = ch + str;
		num = num/10;
	}

	return str;
}

int main()
{
	string str = "123";
	cout << string2int(str) << endl;

	cout << int2string(1236) << endl;
	
	char ch[10];	
	int2char(124, ch);
	cout << ch << endl;

	cout << int2string2(324) << endl;
	return 1;
}