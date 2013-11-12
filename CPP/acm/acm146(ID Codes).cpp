#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

char s[100];		

void main()
{
	while(gets(s)!=NULL)
	{
		if(strcmp(s,"#")==0) break;

		if(next_permutation(s,s+strlen(s)))
		{
			printf("%s\n",s);
		}
		else printf("No Successor\n");
	}
}