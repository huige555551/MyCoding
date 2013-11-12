#include<stdio.h>

long bigmod(long b,long p,long m)
{
	long a;

	if (p==0) return 1;

	if (p%2==0)
	{
		a=bigmod(b,p/2,m)%m;
		return (a*a)%m;
	}
	else
	{
		return ((b%m)*(bigmod(b,p-1,m)%m))%m;
	}
}

void main()
{
	long b,a,k,n;

	while(scanf("%ld %ld %ld",&a,&k,&n)==3)
	{
		b=bigmod(a,k,n);

		printf("%ld\n",b);
	}
}