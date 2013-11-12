#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 100000
#define N 50

char num[MAX][N],array[MAX][N];
char a[MAX];
int p[MAX],j;

void get_num(char *s)
{
	int i,k,l=strlen(s);

	for(i=0,j=0; i<l; i++)
	{
		if( (s[i]>='0'&&s[i]<='9') || (s[i]=='-') || (s[i]=='.') )
		{
			for(k=0; s[i]!=' ' && i<l; i++,k++)
			{
				num[j][k]=s[i];
			}
			num[j][k]=0;
			j++;
			i--;
		}
	}
}

void main()
{
	int i,index,testcase;

	freopen("482.in","r",stdin);

	gets(a);
	testcase=atoi(a);

	while(testcase)
	{
		gets(a);
		gets(a);
		
		get_num(a);

		for(i=0; i<j; i++)
		{
			p[i]=atoi(num[i]);
		}

		gets(a);
		get_num(a);

		for(i=0; i<j; i++)
		{
			index=p[i];
			strcpy(array[index],num[i]);
		}

		for(i=1; i<=j; i++)
		{
			printf("%s\n",array[i]);
		}

		testcase--;

		if(testcase)
			printf("\n");
	}
}