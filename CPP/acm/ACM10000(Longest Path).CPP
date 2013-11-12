#include<stdio.h>
#define MAX 102

long g[MAX][MAX];

long max_re(long a,long b)
{
	if(a>b) return a;
	return b;
}

void main()
{
	long i,j,k,n,s,max,max_in,test=1,t=-MAX*MAX;

	//freopen("in.txt","r",stdin);

	while(scanf("%ld",&n)==1)
	{
		if(n==0) break;

		for(i=1; i<=n; i++)
		{
			for(j=1; j<=n; j++)
			{
				g[i][j]=t;
			}
		}

		scanf("%ld",&s);

		while(scanf("%d %d",&i,&j)==2)
		{
			if(!i && !j) break;

			g[i][j]=1;
		}

		max=0;
		for(k=1; k<=n; k++)
		{
			for(i=1; i<=n; i++)
			{
				for(j=1; j<=n; j++)
				{
					g[i][j]=max_re( g[i][j], g[i][k]+g[k][j] );
				}
			}
		}

		for(i=1; i<=n; i++)
		{
			if(g[s][i]>max)
			{
				max=g[s][i];
				max_in=i;
			}
		}

		printf("Case %ld: ",test++);
		//printf("%ld %ld\n",max,max_in);
		printf("The longest path from %ld has length %ld, finishing at %ld.\n\n",s,max,max_in);


	}
}