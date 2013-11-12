#include<stdio.h>

//#define MAX 10000
#define MAX 9000000

#define TRUE  1
#define FALSE 0

void main()
{
	long prime[MAX],i,j,mid,n,count;

	for(i=0; i<MAX; i++)
		prime[i]=TRUE;

	prime[0]=prime[1]=FALSE;

	for(i=2; i<=MAX; i++)
	{
		if(prime[i]==FALSE)
			continue;

		j=i+i;

		while(j<MAX)
		{
			prime[j]=FALSE;
			j=j+i;
		}

	}

	while(1)
	{
		scanf("%ld",&n);

		if(n==0)
			break;

		mid=n/2;

		count=0;
		for(i=2; i<=mid; i++)
		{
			if(prime[i] && prime[n-i])
				count++;
		}

		printf("%ld\n",count);
	}
}