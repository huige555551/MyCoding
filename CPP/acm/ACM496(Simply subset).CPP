#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 200

int n1[MAX],n2[MAX];
char s1[MAX],s2[MAX];

void get_set()
{
	int i,j,k,list1,list2,set1,set2,zero1,zero2;
	char num[MAX];

	for(i=k=0; i<strlen(s1); i++)
	{
		if(s1[i]>='0' && s1[i]<='9')
		{
			j=0;
			while((s1[i]>='0' && s1[i]<='9'))
			{
				num[j++]=s1[i++];
			}
			num[j]=0;
			n1[k++]=atoi(num);
		}
	}
	list1=k-1;

	for(i=k=0; i<strlen(s2); i++)
	{
		if(s2[i]>='0' && s2[i]<='9')
		{
			j=0;
			while((s2[i]>='0' && s2[i]<='9'))
			{
				num[j++]=s2[i++];
			}
			num[j]=0;
			n2[k++]=atoi(num);
		}
	}
	list2=k-1;

	for(i=0; i<=list1; i++)
	{
		if(n1[i]!=0)
		{
			for(j=0; j<=list2; j++)
			{
				if(n1[i]==n2[j])
				{
					n1[i]=0;
					n2[j]=0;
					break;
				}
			}
		}
	}

	set1=set2=zero1=zero2=1;

	for(i=0; i<=list1; i++)
	{
		if(n1[i]==0)
		{
			zero1=0;
		}
		if(n1[i]!=0)
		{
			set1=0;
		}
	}

	for(j=0; j<=list2; j++)
	{
		if(n2[j]==0)
		{
			zero2=0;
		}
		if(n2[j]!=0)
		{
			set2=0;
		}
	}

	if(zero1==0 && set1==1 && zero2==0 && set2==1) printf("A equals B");
	if(zero1==0 && set1==1 && zero2==0 && set2==0) printf("A is a proper subset of B");
	if(zero1==0 && set1==0 && zero2==0 && set2==1) printf("B is a proper subset of A");
	if(zero1==1 && set1==0 && zero2==1 && set2==0) printf("A and B are disjoint");
	if(zero1==0 && set1==0 && zero2==0 && set2==0) printf("I'm confused!");

	printf("\n");
}

void main()
{
	int i;

	/*freopen("496.in","r",stdin);*/

	while(gets(s1)!=NULL)
	{
		gets(s2);

		for(i=0; i<MAX; i++)
		{
			n1[i]=0;
			n2[i]=0;
		}

		get_set();
	}
}