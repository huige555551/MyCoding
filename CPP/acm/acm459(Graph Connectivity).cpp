#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int p[30];

int find(int x)
{
	while(p[x]>=0)
		x=p[x];

	return x;
}

void set_union(int a,int b)
{
	int temp;

	temp=p[a]+p[b];
		
	if(p[a]>p[b])// if a has fewer nodes
	{
		p[a]=b;  //set parent of a=b
		p[b]=temp;
	}
	else // b has fewer or equal nodes
	{
		p[b]=a;
		p[a]=temp;
	}
}

void main()
{
	int i,test,n,count,r1,r2;
	char s[100];

	//freopen("in.txt","r",stdin);

	gets(s);
	test=atoi(s);

	gets(s);

	while(test)
	{
		gets(s);
		n=s[0]-'A'+1;

		for(i=1; i<=n; i++)	p[i]=-1;

		while(gets(s))
		{
			if(strcmp(s,"")==0) break;

			r1=find(s[0]-'A'+1);
			r2=find(s[1]-'A'+1);

			if(r1!=r2)	set_union(r1,r2);
		}

		count=0;
		for(i=1; i<=n; i++) 
		{
			if(p[i]<0) count++;
		}

		printf("%d\n",count);

		test--;
	}
}