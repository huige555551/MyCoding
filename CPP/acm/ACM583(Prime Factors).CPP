#include<stdio.h>
#include<math.h>

#define MAX 5000
#define P 46401

long factor[MAX];
long prime[P];
long p[MAX];

void main()
{
	long n,count,i;
	long j;

	/*freopen("in.txt","r",stdin);*/
	prime[0]=prime[1]=1;

	for(i=2; i<=(long)sqrt(P-1); i++)
	{
		if(prime[i]==0)
		{
			for(j=i*i; j<=P-1; j=j+i)
			{
				prime[j]=1;
			}
		}
	}
	j=0;
	for(i=0; i<=P-1; i++)
	{
		if(prime[i]==0) p[j++]=i;
	}
	
	while(scanf("%ld",&n)!=EOF)
	{
		if(n==0) break;

		printf("%ld = ",n);

		if(n<0)
		{
			printf("-1 x ");
			n=-n;
		}

		count=0;
		for(i=0; p[i]<=(long)sqrt(n); i++)
		{
			while(n%p[i]==0)
			{
				n=n/p[i];
				factor[count]=p[i];
				count++;
			}
		}
		if(n!=1) factor[count++]=n;

		for(i=0; i<count; i++)
		{
			printf("%ld",factor[i]);
			if(i!=count-1)printf(" x ");
		}
		printf("\n");
	} 
}
