#include<stdio.h>

void main()
{
	long n,i,t;

	while(scanf("%ld",&n)!=EOF)
	{
		for(i=1,t=1; i<=n; i++)
		{
			t=t*i;

			while(t%10==0)
				t=t/10;

			t=t%100000;
		}

		while(t%10==0)
				t=t/10;

		t=t%10;

		printf("%5ld -> %ld\n",n,t);
	}
}

