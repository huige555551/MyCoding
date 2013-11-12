#include<stdio.h>
#include<math.h>

#define MAX 10002

bool prime[MAX];

void main()
{
	long i,j,k,test,start,n;

	//freopen("in.txt","r",stdin);

	prime[0]=prime[1]=1;
	k=(long)sqrt(MAX-1);
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

	scanf("%ld",&test);

	while(test)
	{
		scanf("%ld",&n);

		start=(n/2)+1;

		for(i=start; ;i++)
		{
			if(prime[i]==0)
			{
				printf("%ld\n",i);
				break;
			}
		}

		test--;
	}
}