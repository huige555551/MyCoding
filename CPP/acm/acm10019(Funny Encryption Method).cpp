#include<stdio.h>
#include<math.h>

long dec_to_bin(long n)
{
	long i,count,t;
	
	i=count=t=0;
	while(n)
	{
		t=n%2;
		if(t) count++;
		n=n/2;
	}

	return count;
}

long hex_to_dec(long n)
{
	long i,d,t;

	i=d=t=0;
	while(n)
	{
		t=n%10;
		d+=t*(long)pow(16,i++);
		n=n/10;
	}

	return d;
}

void main()
{
	long test,b1,b2,n;

	//freopen("in.txt","r",stdin);

	scanf("%ld",&test);

	while(test)
	{
		scanf("%ld",&n);

		b1=dec_to_bin(n);
		b2=hex_to_dec(n);
		b2=dec_to_bin(b2);

		printf("%ld %ld\n",b1,b2);

		test--;
	}
}