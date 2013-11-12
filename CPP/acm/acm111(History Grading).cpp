#include<stdio.h>

#define MAX 2000

int a[MAX],b[MAX],c[MAX],d[MAX];

int LCSlength(int n) 
{
	int i,j,k;

	for(i=0; i<=n; i++) a[i]=0;
	for(j=0; j<=n; j++) c[j]=0;

	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++) 
		{ 
			if (b[i]==d[j]) 
			{
				//c[i][j]=c[i-1][j-1]+1;       
				c[j]=a[j-1]+1;
			}
			else if (a[j]>=c[j-1]) 
			{
				//c[i][j]=c[i-1][j];        
				c[j]=a[j];
			}
			else 
			{
				//c[i][j]=c[i][j-1];       
				c[j]=c[j-1];
			} 
		}
		for(k=1; k<=n; k++){ a[k]=c[k]; }
	}

	return c[n];
}

void main()
{
	int i,n,t;

	//freopen("in.txt","r",stdin);

	scanf("%d",&n);

	for(i=1; i<=n; i++)
	{
		scanf("%d",&t);
		b[t]=i;
	}
	
	while(scanf("%d",&t)!=EOF)
	{
		d[t]=1;
		for(i=2; i<=n; i++)
		{
			scanf("%d",&t);
			d[t]=i;
		}

		printf("%d\n",LCSlength(n));
	}
}