#include<stdio.h>
#include<string.h>

#define MAX 1000000

void main()
{
	int i,j;
	char s[MAX],t[MAX],z[MAX];

	while(scanf("%s %s",s,t)!=EOF)
	{

		for(i=0,j=0; t[j]; j++)
		{
			if(t[j]==s[i])
			{
				z[i]=s[i];
				i++;
			}
		}
		z[i]=0;

		if(!strcmp(s,z))
			printf("Yes\n");
		else
			printf("No\n");
	}
}