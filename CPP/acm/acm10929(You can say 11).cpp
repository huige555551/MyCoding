#include<stdio.h>
#include<string.h>

char s[1002];

void main()
{
	int i,t,mod;

	while(scanf("%s",s)==1)
	{
		if(strcmp(s,"0")==0) break;

		t=0;
		for(i=0; i<strlen(s); i++)
		{
			mod=(t+(s[i]-'0'))%11;
			t=mod*10;
		}

		if(mod==0) printf("%s is a multiple of 11.\n",s);
		else printf("%s is not a multiple of 11.\n",s);
	}
}