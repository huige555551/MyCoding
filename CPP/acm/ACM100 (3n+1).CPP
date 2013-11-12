#include<stdio.h>

long counter(long n);

void main()
{
	long first,second,i,mini,maxi,max,a;

	while((scanf("%ld%ld",&first,&second))==2)
	{
		max=0;
		if(first<=second)
		{
			mini=first;
			maxi=second;
		}
		else
		{
			mini=second;
			maxi=first;
		}
		for(i=mini; i<=maxi; i++)
		{
			a=counter(i);
			if(a>max) max=a;
		}

		printf("%ld %ld %ld\n",first,second,max);
	}

}

long counter(long n)
{
	int i;

	for(i=1; n>1; i++)
	{
		if((n%2)==0) n=n/2;
		else n=(3*n)+1;
	}
	return i;
}