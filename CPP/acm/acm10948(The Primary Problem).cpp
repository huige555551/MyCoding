#include<stdio.h>
#include<math.h>

#define MAX 1000003

bool prime[MAX];

void main()
{
	long i,j,k,n,noway;

	//freopen("in.txt","r",stdin);

	k=sqrt(MAX-1);
	
	prime[0]=prime[1]=1;
	for(i=2; i<=k; i++)
	{
		if(prime[i]==0)
		{
			for(j=i*i; j<=MAX-1; j+=i)
			{
				prime[j]=1;
			}
		}
	}

	while(scanf("%ld",&n)==1)
	{
		if(n==0) break;

		printf("%ld:\n",n);

		noway=1;
		for(i=2; i<=n/2; i++)
		{
			if(prime[i]==0 && prime[n-i]==0)
			{
				printf("%ld+%ld\n",i,n-i);
				noway=0;
				break;
			}
		}
		if(noway)printf("NO WAY!\n");
	}
}