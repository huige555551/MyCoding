#include<stdio.h>

int check[10001];

void main()
{
	long long Z,I,M,L,i,count,a,cage=0;

	while(1)
	{
		for(i=0; i<=10000; i++)
		{
			check[i]=0;
		}

		scanf("%lld %lld %lld %lld",&Z,&I,&M,&L);

		if(Z==0 && I==0 && M==0 && L==0)
		{
			break;
		}

		count=1;
		a=L;
		check[L]=1;

		while(1)
		{
			L=((Z*L)+I)%M;

			if(check[L]==1)
			{
				if(L!=a)
					count--;
				break;
			}
			count++;
			check[L]=1;
		}

		printf("Case %lld: ",++cage);
		printf("%lld\n",count);
	}
}