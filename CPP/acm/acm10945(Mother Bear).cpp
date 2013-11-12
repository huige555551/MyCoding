#include<stdio.h>
#include<string.h>
#include<ctype.h>
	
char s[200],t[200];

void main()
{
	char c;
	int i,j,l;

	//freopen("in.txt","r",stdin);

	while(gets(s))
	{
		if(strcmp(s,"DONE")==0) break;

		l=strlen(s);
		
		for(i=j=0; i<l; i++)
		{
			if((s[i]=='.') || (s[i]==',') || (s[i]=='!') || (s[i]=='?') || (s[i]==' '));
			else 
			{
				t[j++]=tolower(s[i]);
			}
		}
		t[j]=0;

		strcpy(s,t);
		l=strlen(t);

		for(i=0,j=l-1; i<l/2; i++,j--)
		{
			c=t[i];
			t[i]=t[j];
			t[j]=c;
		}	

		if(strcmp(s,t)==0) printf("You won't be eaten!\n");
		else printf("Uh oh..\n");
	}
}