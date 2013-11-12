#include<stdio.h>

long long fibo[55];

void main()
{
	long long i,test,n;

	fibo[0]=1;
	fibo[1]=2;

	for(i=2; i<52; i++)
	{
		fibo[i]=fibo[i-1]+fibo[i-2];
	}

	scanf("%lld",&test);

	i=1;
	while(i<=test)
	{
		scanf("%lld",&n);
		
		printf("Scenario #%lld:\n",i);
		printf("%lld\n\n",fibo[n]);

		i++;
	}
}