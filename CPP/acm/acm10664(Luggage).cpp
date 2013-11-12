#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

#define  MAX  202

int luggage[30];
char s[MAX];

int get_num()
{
	int l=strlen(s),i,j,k=0;
	char t[30];

	for(i=0; i<l; i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			j=0;
			while(s[i]>='0' && s[i]<='9')
			{
				t[j++]=s[i++];
			}
			t[j]=0;
			luggage[++k]=atoi(t);
		}
	}
	return k;
}

void main()
{
	int test,n,i,sum1,sum2;

	freopen("in.txt","r",stdin);

	gets(s);
	test=atoi(s);

	while(test)
	{
		gets(s);

		n=get_num();

		sort(luggage,luggage+n+1);

		sum1=sum2=0;

		for(i=n; i>=1; i--)
		{
			if(sum1<=sum2)
			{
				sum1+=luggage[i];
			}
			else 
			{
				sum2+=luggage[i];
			}
		}

		if(sum1==sum2)
			printf("YES\n");
		else 
			printf("NO\n");

		test--;
	}
}