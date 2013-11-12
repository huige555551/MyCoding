#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 5001

char name[MAX][50];
long n,r;
long p[MAX];
long max;

long find(long x)
{
	while(p[x]>=0)
		x=p[x];

	return x;
}

void set_union(long a,long b)
{
	long temp;

	temp=p[a]+p[b];
	if(max<-(temp))max=-temp;
	
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

int sort_function( const void *a, const void *b)
{
	return( strcmp((char *)a,(char *)b) );
}

long search(char *s)
{
	long low,mid,high,value;

	low=1;
	high=n;

	while(low<=high)
	{
		mid=(low+high)/2;
		value=strcmp(s,name[mid]);

		//if(x[mid]==key)
		if(value==0)
			break;
		//else if(key<x[mid])
		else if(value<0)
			high=mid-1;
		else
			low=mid+1;
	}
	if(low>high) return 0;
	return mid;

}

void main()
{
	char s1[50],s2[50];
	long i,p1,p2,r1,r2;

	//freopen("in.txt","r",stdin);

	while(scanf("%ld %ld",&n,&r)==2)
	{
		if(n==0 && r==0) break;

		for(i=1; i<=n; i++)
		{
			scanf("%s",name[i]);
		}

		qsort((void *)name, n+1, sizeof(name[0]), sort_function);
		
		for(i=1; i<=n; i++)	p[i]=-1;
		max=1;

		for(i=1; i<=r; i++)
		{
			scanf("%s %s",s1,s2);

			p1=search(s1);
			p2=search(s2);

			r1=find(p1);
			r2=find(p2);

			if(r1!=r2) set_union(r1,r2);
		}

		printf("%ld\n",max);
	}
}