#include<stdio.h>
#include<string.h>

#define MAX(a,b) a>b?a:b

void main()
{
	char s[100][102],temp[102];
	int i,j,k,l,max;

	k=max=0;
	while(gets(temp)!=NULL)
	{
		strcpy(s[k++],temp);
		max=MAX(max,strlen(temp));
	}

	for(j=0; j<max; j++)
	{
		for(i=k-1; i>=0; i--)
		{
			l=strlen(s[i]);

			if(j>=l)
			{
				putchar(' ');
			}
			else
			{
				putchar(s[i][j]);
			}
		}

		printf("\n");
	}
}