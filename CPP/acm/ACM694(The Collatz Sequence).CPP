#include<stdio.h>

long long count(long long a,long long l)
{
	long long i;

	for(i=1; a!=1; i++)
	{
		if(a%2==0)
			a=a/2;
		else
		{
			a=(3*a)+1;

			if(a>l)
				break;
		}
	}

	return i;
}

void main()
{
	long long a,l,term,i=1;

	while(1)
	{
		scanf("%lld %lld",&a,&l);

		if(a<0 && l<0)
			break;

		term=count(a,l);

		printf("Case %lld: A = %lld, limit = %lld, number of terms = %lld\n",i,a,l,term);
                
		i++;
	}
}


