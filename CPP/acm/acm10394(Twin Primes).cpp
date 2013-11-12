#include<stdio.h>
#include<math.h>

#define MAX 19000001
//bool use na kore long prime[MAX] use korle memory limit exceeded error dekhabe
//You can speed it up also by checking numbers next to multiples of 6, since every pair of twin primes is next to multiples of 6.

bool prime[MAX];
long pair[100002][2];

void main()
{
	long i,j,k;

	prime[0]=prime[1]=1;
	for(i=2; i<=sqrt(MAX); i++)
	{
		if(prime[i]==0)
		{
			for(j=i*i; j<MAX; j+=i)
			{
				prime[j]=1;		
			}
		}
	}

	k=3;j=0;
	for(i=5; i<MAX&&j<=100000; i++)
	{
		if(prime[i]==0)
		{
			if(i-k==2)
			{
				pair[j][0]=k;
				pair[j][1]=i;
				j++;				
			}
			k=i;
		}
	}

	while(scanf("%ld",&k)==1)
	{
		printf("(%ld, %ld)\n",pair[k-1][0],pair[k-1][1]);
	}
}
