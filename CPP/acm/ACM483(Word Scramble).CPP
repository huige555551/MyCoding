#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX 10000

/*Seem so simple but Not so simple*/

void main()
{
	char c,s[MAX]={0};
	int i=0,j;

/*	freopen("483.in", "r", stdin);*/
/*	freopen("483.out", "w", stdout);*/

	while((c=getchar())!=EOF)
	{
		if(isspace(c))
		{
			if(i==0)
				putchar(c);
			else
			{
				s[i]=0;
				for(j=strlen(s)-1; j>=0; j--)
				{
					putchar(s[j]);
				}

				i=0;
				putchar(c);
			}
		}

		else
		{
			s[i++]=c;
		}
	}

	if(i!=0)
	{
		s[i]=0;
		for(j=strlen(s)-1; j>=0; j--)
		{
			putchar(s[j]);
		}

	}
}

/*
whitespace means:tabs,newline,vertical tabs,carriage return,space,form feed etc.
so:  int isspace(c) :  is very useful to check whitespace.

think:
INPUT::sohag^Z
its OUTPUT sohould be::sohag
For this: later i have to use another condition.BE CAREFUL
i made mistake first time.
*/