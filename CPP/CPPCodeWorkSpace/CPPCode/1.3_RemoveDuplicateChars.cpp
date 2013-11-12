#include <iostream>
#include <string>
#include <vector>
using namespace std;

void removeDuplicate(char *str)
{
	if(str==NULL) return;

	int len = strlen(str);
	int tail = 0;

	for(int i=0; i<len; i++){		
		bool dup = false;

		for(int j=0; j<tail; j++){

			if(str[i]==str[j]){
				dup = true;
				break;
			}	
		}

		if(!dup){
			str[tail++] = str[i];
		}
	}
	str[tail] = '\0';
}

void removeDuplicateBuffer(char *str)
{
	if(str==NULL) return;

	vector<bool> buffer(256, false);
	int len = strlen(str);
	int tail = 0;

	for(int i=0; i<len; i++){		
		
		if(!buffer[str[i]]) {
			str[tail++] = str[i];
			buffer[str[i]] = true;
		}		
	}
	str[tail] = '\0';
}

void main()
{
	char str[100], str2[100];

	while(scanf("%s", str)!=EOF){
		strcpy(str2, str);

		removeDuplicate(str);
		cout << str << endl;
		removeDuplicateBuffer(str2);
		cout << str2 << endl;
	}
}