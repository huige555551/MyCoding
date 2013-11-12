#include<stdio.h>
#include<stdlib.h>

#define MAX 200

void main()
{
	int i,j,count,correct;
	char s[MAX],n[MAX];

	freopen("673.in","r",stdin);

	gets(n);

	count=atoi(n);

	while(count)
	{
		gets(s);

		correct=1;
		for(i=0; s[i]; i++)
		{
			if(s[i]==')')
			{
				for(j=i-1; j>=0; j--)
				{
					if(s[j]=='(')
					{
						s[j]='0';
						s[i]='0';
						break;
					}
					else if(s[j]=='['||s[j]==']')
					{
						correct=0;
						break;
					}
				}
			}
			else if(s[i]==']')
			{
				for(j=i-1; j>=0; j--)
				{
					if(s[j]=='[')
					{
						s[j]='0';
						s[i]='0';
						break;
					}
					else if(s[j]=='('||s[j]==')')
					{
						correct=0;
						break;
					}
				}
			}
			if(!correct)
				break;
		}

		for(i=0; s[i]; i++)
		{
			if(s[i]=='('||s[i]==')'||s[i]=='['||s[i]==']')
			{
				correct=0;
				break;
			}
		}

		if(correct)
			printf("Yes\n");
		else
			printf("No\n");

		count--;
	}
}