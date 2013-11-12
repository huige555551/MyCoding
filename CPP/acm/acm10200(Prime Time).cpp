#include<stdio.h>
#include<math.h>

int p[10001];

int isprime(long n)
{
	int i,k;

	if(n==0 || n==1) return 0;

	k=sqrt(n);
	for(i=2; i<=k; i++)
	{
		if(n%i==0)
		{
			return 0;
		}
	}
	return 1;
}

void main()
{
	long a,b,i,n,d,count;
	double per;

	//freopen("in.txt","r",stdin);

	for(i=0; i<=10000; i++)
	{
		n=(i*i) + i + 41;
		if(isprime(n)) count++;
		p[i]=count;
	}

	while(scanf("%ld %ld",&a,&b)==2)
	{
		d=p[b]-p[a];
		
		if(isprime((a*a)+a+41)) d++;

		per=(d*100.0)/(b-a+1.0);
		
		printf("%.2lf\n",per);

	}
}