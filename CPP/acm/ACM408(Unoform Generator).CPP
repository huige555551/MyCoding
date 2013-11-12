#include<stdio.h>

#define TRUE  1
#define FALSE 0
//#define MAX  100006
#define MAX 10000

long long p[MAX];

void main()
{
	long long a,b,i,mod,s,check;

	while(scanf("%lld %lld",&a,&b)==2)
	{
		printf("%10lld%10lld",a,b);

		for(i=0; i<=b; i++)
			p[i]=FALSE;

		for(s=b,i=0; i<=b-1; i++)
		{
			mod=s%b;
			p[mod]=TRUE;
			s=s+a;
		}

		check=TRUE;
		for(i=0; i<=b-1; i++)
		{
			if(!p[i])
			{
				check=FALSE;
				break;
			}
		}

		if(check)
			printf("    Good Choice\n");
		else
			printf("    Bad Choice\n");
	}
}