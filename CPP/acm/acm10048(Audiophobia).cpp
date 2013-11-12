#include<stdio.h>

#define MAX 102
#define INF 32767

int d[MAX][MAX];

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

void all_pairs_shortest_paths(int v)
{
	int i,j,k;

	for(k=1; k<=v; k++)
	{
		for(i=1; i<=v; i++)
		{
			for(j=1; j<=v; j++)
			{
				d[i][j]=min(d[i][j],max(d[i][k],d[k][j]));
			}
		}
	}

}

void main()
{
	int i,j,source,dest,cost,v,e,q,test=1;

	//freopen("in.txt","r",stdin);

	while(scanf("%d %d %d",&v,&e,&q)==3)
	{
		if(v==0 && e==0 && q==0) break;

		for(i=1; i<=v; i++)
		{
			for(j=1; j<=v; j++)
			{
				d[i][j]=INF;
			}
		}
		for(i=1; i<=v; i++)	d[i][i]=0;
		
		for(i=1; i<=e; i++)
		{
			scanf("%d %d %d",&source,&dest,&cost);

			d[source][dest]=cost;
			d[dest][source]=cost;
		}

		all_pairs_shortest_paths(v);

		printf("Case #%d\n",test++);
		for(i=1; i<=q; i++)
		{
			scanf("%d %d",&source,&dest);

			if(d[source][dest]!=INF)
				printf("%d\n",d[source][dest]);
			else
				printf("no path\n");
		}
		printf("\n");
	}
}