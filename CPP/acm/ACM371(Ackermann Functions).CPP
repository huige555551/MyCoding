#include<stdio.h>

long long counter(long long n);

void main()
{
	long long first,second,i,mini,maxi,max,a,num;

	while(1)
	{
		scanf("%lld%lld",&first,&second);

		if(first==0 && second==0)
		{
			break;
		}

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
			if(a>max)
			{
				max=a;
				num=i;
			}
		}

		printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",mini,maxi,num,max);
	}

}

long long counter(long long n)
{
	long long i=0;

	do	
	{
		if((n%2)==0) 
			n=n/2;
		else
			n=(3*n)+1;

		i++;
	}while(n!=1);

	return i;
}

/*
CRITICAL INPUT:
1 2
2 1

OUTPUT:

Between 1 and 2, 1 generates the longest sequence of 3 values.
Between 1 and 2, 1 generates the longest sequence of 3 values.
*/