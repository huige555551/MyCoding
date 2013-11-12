#include<stdio.h>
#include<math.h>

#define MAX 31630

int prime[MAX];
long p[3500];

int digit_sum(long n)
{
	int t=0;

	while(n)
	{
		t+=n%10;
		n=n/10;
	}

	return t;
}

void main()
{
	long i,j,k,n,test,t,not_prime,sum1,sum2;

	k=180;
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

	for(i=j=0; i<=MAX-1; i++)
	{
		if(prime[i]==0) p[j++]=i;
	}

	scanf("%ld",&test);

	while(test)
	{
		scanf("%ld",&n);

		k=0;
		for(i=n+1; ; i++)
		{
			sum1=digit_sum(i);
			t=i;sum2=0;not_prime=0;
			for(j=0; p[j]<=sqrt(t); j++)
			{
				if(t%p[j]==0)
				{
					while(t%p[j]==0)
					{
						sum2+=digit_sum(p[j]);
						t=t/p[j];
						not_prime=1;
					}
				}
			}
			if(t!=1 && not_prime) sum2+=digit_sum(t);

			if(sum1==sum2)
			{ 
				printf("%ld\n",i);
				break;
			}
		}
		test--;
	}	
}