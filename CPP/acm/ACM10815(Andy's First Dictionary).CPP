#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define MAX 100000
#define M 100

char word[MAX][M];
int j;

void get_word(char *s)
{
	int i,k;

	for(i=0; i<strlen(s); i++)
	{
		if( (s[i]>='a'&&s[i]<='z') || (s[i]>='A'&&s[i]<='Z') )
		{
			for(k=0; (s[i]>='a'&&s[i]<='z') || (s[i]>='A'&&s[i]<='Z'); i++,k++)
			{
				word[j][k]=tolower(s[i]);
			}
			i--;
			j++;
		}
	}
}

int sort_function( const void *a, const void *b)
{
	return( strcmp((char *)a,(char *)b) );
}

void main()
{
	char s[202];
	int i;

	//freopen("in.txt","r",stdin);

	while(gets(s))
	{
		get_word(s);
	}

	qsort(word[0], j, M, sort_function);

	for(i=0; i<j; i++)
	{
		if(i!=0 && strcmp(word[i],word[i-1])!=0)
		{
			printf(word[i]);
		}
		else if(i==0)
		{
			printf(word[i]);
		}
		else
			continue;

		printf("\n");
	}
}