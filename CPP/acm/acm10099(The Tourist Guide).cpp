#include<stdio.h>
#include<math.h>

int p[101][101];

int min(int a,int b)
{
	if(a<b) return a;
	return b;
}

int max(int a,int b)
{
	if(a>b) return a;
	return b;
}

void main()
{
	int trip,i,j,k,n,m,source,destination,tourist,cost,test=1;

	//freopen("in.txt","r",stdin);

	while(scanf("%d %d",&n,&m)==2)
	{
		if(n==0 && m==0) break;

		printf("Scenario #%d\n",test++);

		for(i=1; i<=n; i++)
		{
			for(j=1; j<=n; j++)
			{
				p[i][j]=0;
			}
		}

		for(i=1; i<=m; i++)
		{
			scanf("%d %d %d",&j,&k,&cost);
			p[j][k]=cost;
			p[k][j]=cost;
		}

		scanf("%d %d %d",&source,&destination,&tourist);

		for(k=1; k<=n; k++)
		{
			for(i=1; i<=n; i++)
			{
				for(j=1; j<=n; j++)
				{
					p[i][j]=max(p[i][j],min(p[i][k],p[k][j]));
				}
			}
		}
/*
		for(i=1; i<=n; i++)
		{
			for(j=1; j<=n; j++)
			{
				printf("%d ",p[i][j]);
			}
			printf("\n");
		}
*/
		i=p[source][destination]-1;

		trip=(int)ceil(double(tourist)/double(i));

		printf("Minimum Number of Trips = %d\n",trip);
	}

}
