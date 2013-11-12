#include<stdio.h>
#include<math.h>

#define MAX 1000002

int prime[MAX];
long p[MAX];

int digit_prime(long n)
{
	long m=0;

	while(n)
	{
		m+=(n%10);
		n/=10;
	}

	if( (prime[m]==0) || (prime[m]==2)) return 1;
	return 0;
}

void main()
{
	long i,j,k,n,n1,n2,sum;

	//freopen("in.txt","r",stdin);

	k=(long)sqrt(MAX-1);

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

	sum=0;
	for(i=0; i<=MAX-1; i++)
	{
		if(prime[i]==0)
		{
			if(digit_prime(i))
			{
				prime[i]=2;
				sum++;
			}
		}
		p[i]=sum;
	}

	scanf("%ld",&n);

	while(n)
	{
		scanf("%ld %ld",&n1,&n2);

		i=p[n2]-p[n1];

		if(i==0 && prime[n1]==2)
		{
			i=1;
		}
		else if(prime[n1]==2)
		{
			i+=1;
		}
		else ;
		
		printf("%ld\n",i);

		n--;
	}
}





