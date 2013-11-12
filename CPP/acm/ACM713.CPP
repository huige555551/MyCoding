#include<stdio.h>
#include<math.h>

long long reverse_num(long long n)
{
	long long l,temp,rev_n=0;

	temp=n;
	for(l=0; temp; l++)
	{
		temp/=10;
	}

	for(l; l; l--)
	{
		rev_n+=(n%10)*pow(10,l-1);
		n/=10;
	}

	return rev_n;
}

void main()
{
	long long count,n1,n2,sum;

	scanf("%lld",&count);

	while(count)
	{
		scanf("%lld %lld",&n1,&n2);

		n1=reverse_num(n1);
		n2=reverse_num(n2);

		sum=n1+n2;

		sum=reverse_num(sum);

		printf("%lld\n",sum);

		count--;
	}
}