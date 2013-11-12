#include<stdio.h>

void main()
{
	long n;

	while(scanf("%ld",&n)==1)
	{
		if(n==0) break;

		else if(n>100) printf("f91(%ld) = %ld\n",n,n-10);
		else printf("f91(%ld) = 91\n",n);
	}
}