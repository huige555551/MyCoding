#include<stdio.h>

long long num[10000];

void main()
{
	long long n1,n2,boring,i,j;

	freopen("in.txt","r",stdin);

	while(scanf("%lld %lld",&n1,&n2)==2)
	{
                boring=1;
		for(i=0; n1>1 && n2>1; i++)
		{
			num[i]=n1;

			if(n1%n2==0)
			{
				n1=n1/n2;
				boring=0;
			}
			else
			{
				boring=1;
				break;
			}
		}

		if(!boring)
		{
			num[i]=1;

			for(j=0; j<=i; j++)
			{
				printf("%lld",num[j]);

				if(j<i)
					printf(" ");
			}
		}
		else
			printf("Boring!");

		printf("\n");
	}
}