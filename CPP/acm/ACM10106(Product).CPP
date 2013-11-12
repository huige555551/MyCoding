#include<stdio.h>
#include<string.h>

#define MAX 500

void str_rev(char *p)
{
	char s[2*MAX]={0};
	int i,j;

	for(i=strlen(p)-1,j=0; i>=0; j++,i--)
	{
		s[j]=p[i];
	}

	for(i=0; s[i]; i++)
	{
		p[i]=s[i];
	}
}

void big_multiplication(char *s1,char *s2)
{
	char ans[2*MAX]={0};
	int i,j,l1,l2,num1,num2;

	str_rev(s1);
	str_rev(s2);

	l1=strlen(s1);
	l2=strlen(s2);

	for(i=0; i<l2; i++)
	{
		num2=s2[i]-'0';

		for(j=0; j<l1; j++)
		{
			num1=s1[j]-'0';

			ans[i+j]+=num1*num2;

			if(ans[i+j]>9)
			{
				ans[i+j+1]+=ans[i+j]/10;
				ans[i+j]%=10;
			}
		}
	}

	for(i=0; i<(l1+l2); i++)
	{
		ans[i]+='0';
	}

	str_rev(ans);

	while(ans[0]=='0')
	{
		for(i=0; i<(l1+l2); i++)
		{
			ans[i]=ans[i+1];    /* setting number  in actual order */
		}
	}

	if(!strcmp(ans,""))
	{
		strcpy(ans,"0");
	}

	printf(ans);
}

void main()
{
	char n1[MAX],n2[MAX];

	while(scanf("%s %s",n1,n2)==2)
	{
		big_multiplication(n1,n2);

		printf("\n");
	}
}