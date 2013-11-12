#include<stdio.h>
#include<math.h>

void main()
{
	long long n,i;

	while(scanf("%lld",&n)==1)
	{
		if(n<0) break;

		for(i=2; i<=sqrt(n); i++)
		{
			while(n%i==0)
			{
				printf("    %lld\n",i);
				n=n/i;
			}
		}
		if(n!=1) printf("    %lld\n",n);
	}
}