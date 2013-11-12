#include<stdio.h>
#include<string.h>

#define MAX 100

void main()
{
	char s[MAX],x[MAX];
	int i,j;

	while(gets(s)!=NULL)
	{
		j=0;

		for(i=0; i<strlen(s); i++)
		{
			if((s[i]=='B')||(s[i]=='F')||(s[i]=='P')||(s[i]=='V'))
			{
				if((s[i-1]!='B')&&(s[i-1]!='F')&&(s[i-1]!='P')&&(s[i-1]!='V'))
					x[j++]='1';
			}
			else if((s[i]=='C')||(s[i]=='G')||(s[i]=='J')||(s[i]=='K')||(s[i]=='Q')||(s[i]=='S')||(s[i]=='X')||(s[i]=='Z'))
			{
				if((s[i-1]!='C')&&(s[i-1]!='G')&&(s[i-1]!='J')&&(s[i-1]!='K')&&(s[i-1]!='Q')&&(s[i-1]!='S')&&(s[i-1]!='X')&&(s[i-1]!='Z'))
					x[j++]='2';
			}
			else if((s[i]=='D')||(s[i]=='T'))
			{
				if((s[i-1]!='D')&&(s[i-1]!='T'))
					x[j++]='3';
			}
			else if((s[i]=='L'))
			{
				if((s[i-1]!='L'))
					x[j++]='4';
			}
			else if((s[i]=='M')||(s[i]=='N'))
			{
				if((s[i-1]!='M')&&(s[i-1]!='N'))
					x[j++]='5';
			}
			else if((s[i]=='R'))
			{
				if((s[i-1]!='R'))
					x[j++]='6';
			}
			else;
		}
		x[j]=0;

		printf(x);
		printf("\n");
	}
}