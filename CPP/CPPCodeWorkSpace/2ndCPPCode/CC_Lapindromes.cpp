#include <iostream>
#include <string>
using namespace std;

bool lapindrome(string str)
{
	int len = str.length();
	int ch[26] = {0};

	for(int i=0; i<len/2; i++){
		ch[str[i]-'a']++;
	}

	int j = len/2;
	if(len%2!=0) j++;	

	for(j; j<len; j++){
		ch[str[j]-'a']--;
	}

	for(int k=0; k<26; k++){
		if(ch[k]) return false;
	}

	return true;
}

int main()
{
	//freopen("in.txt", "r", stdin);

	int n;
	string str;

	cin >> n;

	while(n--){
		cin >> str;
		cout << (lapindrome(str)?"YES":"NO") << "\n";
	}
	return 0;
}