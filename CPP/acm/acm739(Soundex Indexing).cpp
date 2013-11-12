#include<stdio.h>
#include<string.h>

char s[21];

char get_digit(char c)
{
	if(c=='B' || c=='P' || c=='F' || c=='V')
	{
		return '1';
	}
	else if(c=='C' || c=='S' || c=='K' || c=='G' || c=='J' || c=='Q' || c=='X' || c=='Z')
	{
		return '2';
	}
	else if(c=='D' || c=='T')
	{
		return '3';
	}
	else if(c=='L')
	{
		return '4';
	}
	else if(c=='M' || c=='N')
	{
		return '5';
	}
	else if(c=='R')
	{
		return '6';
	}
	else return '0';
}

void main()
{
	int i,j,l,d1,d2;
	char t[5];

	//freopen("in.txt","r",stdin);

	for(i=1; i<10; i++)
	{
		printf(" ");
	}
	printf("%s","NAME");
	for(i=14; i<35; i++)
	{
		printf(" ");
	}
	printf("%s\n","SOUNDEX CODE");

	while(scanf("%s",s)==1)
	{
		for(i=1; i<10; i++)
		{
			printf(" ");
		}
		printf("%s",s);

		strcpy(t,"0000");
		l=strlen(s);
		t[0]=s[0];

		for(i=1,j=1; i<l && j<4; i++)
		{
			if(s[i]!='A' && s[i]!='E' && s[i]!='I' && s[i]!='O' && s[i]!='U' && s[i]!='Y' && s[i]!='W' && s[i]!='H')
			{
				d1=get_digit(s[i-1]);
				d2=get_digit(s[i]);
				if(d1!=d2)
				{
					t[j++]=d2;
				}
			}
		}

		for(i=10+l; i<35; i++)
		{
			printf(" ");
		}

		printf("%s\n",t);
	}
	for(i=1; i<20; i++)
	{
		printf(" ");
	}
	printf("END OF OUTPUT\n");
}