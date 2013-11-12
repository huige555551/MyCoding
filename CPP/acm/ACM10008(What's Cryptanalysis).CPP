#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX 1000

int a[30];

void main()
{
	int count,i,j,c,high;
	char s[MAX],line[80];

	/*freopen("in.txt","r",stdin);*/

	gets(line);

	count=atoi(line);

	while(count)
	{
		gets(s);

		for(i=0; s[i]; i++)
		{
			if(isalpha(s[i]))
			{
				c=toupper(s[i]);
				a[c-65]++;
			}
		}

		count--;
	}

	for(i=0; i<26; i++)
	{
		high=0;

		for(j=1; j<26; j++)
		{
			if(a[high] < a[j])
			{
				high=j;
			}
		}

		if(a[high])
		{
			printf("%c %d\n",high+65,a[high]);

			a[high]=0;
		}

	}
}