#include<stdio.h>

#define MAX 50002

long p[MAX];

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

	if(p[a]>p[b])//if a has fewer nodes than b
	{
		p[a]=b;
		p[b]=temp;
	}
	else
	{
		p[b]=a;
		p[a]=temp;
	}
}

void main()
{
	long n;//no of std,
	long m;//no of pair to input
	long i,r1,r2,test=1,count,a,b;

	//freopen("in.txt","r",stdin);

	while(scanf("%ld %ld",&n,&m)==2)
	{
		if(n==0 && m==0) break;

		for(i=1; i<=n; i++) p[i]=-1;

		for(i=1; i<=m; i++)
		{
			scanf("%ld %ld",&a,&b);

			r1=find(a);
			r2=find(b);

			if(r1!=r2) set_union(r1,r2);
		}
		
		count=0;
		for(i=1; i<=n; i++)
		{
			if(p[i]<0) count++;
		}

		printf("Case %ld: %ld\n",test++,count);
	}
}