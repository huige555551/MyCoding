#include<stdio.h>
#include<ctype.h>
#include<string.h>

void main()
{
	int i,j,n,check=1;
	char s[150];

	/*freopen("in.txt","r",stdin);*/
	/*freopen("out.txt","w",stdout);*/

	while(gets(s)!=NULL)
	{
		if(check==0)
		{
		   putchar('\n');
		}

		check=0;
		n=0;

		for(i=0; i<strlen(s); i++)
		{
			if(isdigit(s[i]))
			{
				n+=s[i]-'0';
			}
			else
			{
				if(s[i]=='!')
				{
					if(i!=strlen(s)-1)
					{
						putchar('\n');
					}
				}
				else
				{
					for(j=n; j>0; j--)
					{
						printf("%c",(s[i]=='b'? ' ': s[i]));
					}
					n=0;
				}
			}
		}
	}
}


/*
IT GETS (PE) :

#include<stdio.h>
#include<ctype.h>
#include<string.h>

void main()
{
	int i,j,n;
	char s[150];

	/*freopen("in.txt","r",stdin);*/
	/*freopen("out.txt","w",stdout);*/

/*	while(gets(s)!=NULL)
	{
		n=0;
		for(i=0; i<strlen(s); i++)
		{
			if(isdigit(s[i]))
			{
				n+=s[i]-'0';
			}
			else
			{
				if(s[i]=='!')
				{
					putchar('\n');
				}
				else
				{
					for(j=n; j>0; j--)
					{
						printf("%c",(s[i]=='b'? ' ': s[i]));
					}
					n=0;
				}
			}
		}

		if(s[i-1]!='!')
		{
			putchar('\n');
		}
	}
}*/