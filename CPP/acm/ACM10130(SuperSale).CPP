#include<stdio.h>
#define N 1000
#define MW 30

int c[N+1][MW+1];
int price[N+1],weight[N+1];

void knapsack(int n)
{
	int i,w,t;

	for(i=0; i<=n; i++) c[i][0]=0;
	for(w=0; w<=MW; w++) c[0][w]=0;
	
	for(i=1; i<=n; i++)
	{
		for(w=1; w<=MW; w++)
		{
			if(weight[i]>w)
			{
				c[i][w]=c[i-1][w];
			}
			else
			{
				t=c[i-1][w-weight[i]]+price[i];
				
				if(c[i-1][w]>t)
				{
					c[i][w]=c[i-1][w];
				}
				else
				{
					c[i][w]=t;
				}
			}
		}
	}

}

void main()
{
	int test,i,sum,n,g,max_weight;

	freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test)
	{
		scanf("%d",&n);
		
		for(i=1; i<=n; i++)
		{
			scanf("%d %d",&price[i],&weight[i]);
		}
		
		knapsack(n);

		scanf("%d",&g);

		sum=0;
		for(i=1; i<=g; i++)
		{
			scanf("%d",&max_weight);
			
			sum+=c[n][max_weight];
		}

		printf("%d\n",sum);
		
		test--;
	}
}