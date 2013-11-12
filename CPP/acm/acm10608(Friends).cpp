#include<stdio.h>

long p[30001];
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

void main()
{
	long i,test,n,m,count,a,b,r1,r2;

	//freopen("in.txt","r",stdin);

	scanf("%ld",&test);	

	while(test)
	{
		max=0;

		scanf("%ld %ld",&n,&m);
		
		for(i=1; i<=n; i++)	p[i]=-1;

		for(count=1; count<=m; count++)
		{
			scanf("%ld %ld",&a,&b);

			r1=find(a);
			r2=find(b);

			if(r1!=r2)	set_union(r1,r2);
		}
		printf("%ld\n",max);

		test--;
	}
}