#include<stdio.h>

#define MAX 10000
//#define MAX 1000002

#define TRUE  1
#define FALSE 0

void main()
{
	long prime[MAX],i,j,mid,n,count;

	for(i=0; i<MAX; i++)
		prime[i]=TRUE;

	prime[0]=prime[1]=prime[2]=FALSE;

	for(i=3; i<=MAX; i++)
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
		for(i=3; i<=mid; i++)
		{
			if(prime[i] && prime[n-i])
			{
				count++;
				printf("%ld = %ld + %ld",n,i,n-i);
				break;
			}
		}

		if(count==0)
			printf("Goldbach's conjecture is wrong.");

		printf("\n");
	}
}