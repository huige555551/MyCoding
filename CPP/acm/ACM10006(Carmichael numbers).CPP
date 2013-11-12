#include<stdio.h>
#include<math.h>

#define MAX 65008

long prime[MAX];
long carmichael[30];

//if m is more than 46340 then it will not work in long
//so i use long long and it worked after a long time debugging
long long bigmod(long long b,long long p,long long m)
{
	long long a;

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
	long i,j,k,n=0,car,a;

	prime[0]=prime[1]=1;
	for(i=2; i<=(long)sqrt(MAX); i++)
	{
		if(prime[i]==0)
		{
			for(j=i*i; j<MAX; j=j+i)
			{
				prime[j]=1;
			}
		}
	}

	for(i=500; i<MAX; i++)
	{
		if(prime[i]==1)
		{
			for(k=2; k<i; k++)
			{
				car=bigmod(k,i,i);
				if(car!=k)
				{
					car=0;
					break;
				}
			}
			if(car) carmichael[n++]=i;
		}
	}

	while(1)
	{
		scanf("%ld",&a);

		if(a==0)break;

		car=0;
		for(i=0; i<n; i++)
		{
			if(a==carmichael[i])
			{
				car=1;
				break;
			}
			else if(a<carmichael[i]) break;
		}

		if(car) printf("The number %ld is a Carmichael number.\n",a);
		else printf("%ld is normal.\n",a);
	}
}