#include<stdio.h>
#include<string.h>

#define MAX 150

char sum[MAX];

void str_rev(char *p)
{
	char s[MAX]={0};
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

void SUM(char *n1,char *n2)
{
	int l1,l2,i,temp,a,carry;

	str_rev(n1);
	str_rev(n2);

	l1=strlen(n1);
	l2=strlen(n2);

	if(l1 > l2)
	{
		for(l2; l2<l1; l2++)
		{
			n2[l2]='0';
			n2[l2+1]=0;
		}
	}
	if(l1 < l2)
	{
		for(l1; l1<l2; l1++)
		{
			n1[l1]='0';
			n1[l1+1]=0;
		}
	}

	carry=0;
	for(i=0; n1[i]; i++)
	{
		temp=n1[i]+n2[i]-96+carry;
		if(temp>9)
		{
			temp=temp-10;
			carry=1;
		}
		else
			carry=0;

		sum[i]=temp+48;
	}

	if(carry==0)
		sum[i]=0;
	else
	{
		sum[i]=carry+48;
		sum[i+1]=0;
	}

	str_rev(sum);
}

void main()
{
	int i,j;
	char n[MAX][MAX];

	for(i=0; ; i++)
	{
		scanf("%s",n[i]);

		if(!strcmp(n[i],"0"))
			break;
	}

	strcpy(sum,n[0]);

	for(j=1; j<=i-1; j++)
	{
		SUM(sum,n[j]);
	}

	printf("%s\n",sum);
}