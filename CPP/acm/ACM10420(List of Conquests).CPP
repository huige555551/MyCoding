#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char c[2001][50];

int sort_function( const void *a, const void *b)
{
	return( strcmp((char *)a,(char *)b) );
}


void main()
{
	char s[100];
	int i,j,n,count;

	//freopen("in.txt","r",stdin);

	gets(s);
	n=atoi(s);

	i=0;
	while(n)
	{
		gets(s);
		sscanf(s,"%s",c[i++]);
		n--;
	}

	qsort(c[0], i, 50, sort_function);

	for(count=1,j=0; j<i; j++)
	{
		if(strcmp(c[j],c[j+1])!=0)
		{
			printf("%s %d\n",c[j],count);
			count=1;
		}
		else 
		{
			count++;
		}
	}
}