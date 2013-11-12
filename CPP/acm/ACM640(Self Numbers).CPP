#include <stdio.h>

long a[1000006];

long sum_of_dgt(long n)
{
	long i=0;

	while(n)
	{
		i+=n%10;
		n=n/10;
	}

	return i;
}

void main()
{

	long register i,n;

	//freopen("out1.txt","w",stdout);

	for(i=1; i<=1000000; i++)
	{
		n=i+sum_of_dgt(i);
		if(n<=1000000)
			a[n]=1;
	}

	for(i=1; i<=1000000; i++)
	{
		if(a[i]==0)
			printf("%ld\n",i);
	}
}
