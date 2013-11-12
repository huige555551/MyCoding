#include<stdio.h>
#include<string.h>

#define MAX 300

void reverse_num(char *n)
{
	int i,j,k=0;
	char r[MAX]={0};

	for(j=0,i=strlen(n)-1; i>=0; i--)
	{
		if(n[i]=='0'&&k==0)
		{
			continue;
		}

		k=1;
		r[j++]=n[i];

	}
	r[j]=0;

	for(i=strlen(r)-1; ; i--)
	{
		if(r[i]=='0'&&k==1)
		{
			r[i]=0;
			continue;
		}
		k=0;
		break;
	}

	for(i=0; i<strlen(r); i++)
		n[i]=r[i];
	n[i]=0;
}

void SUM(char *n1,char *n2)
{
	int l1,l2,i,temp,a,carry;
	char sum[MAX];

	reverse_num(n1);
	reverse_num(n2);

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

	reverse_num(sum);

	reverse_num(sum);

	printf(sum);
}

void main()
{
	int count;
	char n1[MAX],n2[MAX],sum[MAX];

	scanf("%d",&count);

	while(count)
	{
		scanf("%s %s",n1,n2);

		reverse_num(n1);
		reverse_num(n2);

		SUM(n1,n2);

		printf("\n");

		count--;
	}
}