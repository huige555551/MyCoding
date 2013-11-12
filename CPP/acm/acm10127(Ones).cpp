#include<stdio.h>

void main()
{
	long n,a,k,one;

	while(scanf("%ld",&n)==1)
	{
		a=one=1;
		while(1)
		{
			while(a<n)
			{
				a=a*10+1;
				one+=1;
			}
			
			k=a%n;
			if(k==0) break;

			a=k;
		}

		printf("%ld\n",one);
	}
}