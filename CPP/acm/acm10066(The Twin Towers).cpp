#include<stdio.h>
#include<string.h>

#define MAX 102

int X[MAX],Y[MAX];
int i,j,k,m,n,c[MAX],a[MAX];

int LCSlength() 
{
	for(i=0; i<=n; i++) a[i]=0;
	for(j=0; j<=n; j++) c[j]=0;

	for (i=1;i<=m;i++)
	{
		for (j=1;j<=n;j++) 
		{ 
			if (X[i]==Y[j]) 
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
	int test=1;
	freopen("in.txt","r",stdin);

	while( scanf("%d %d",&m,&n)==2 )
	{
		if(m==0 && n==0) break;

		for(i=1; i<=m; i++) 
		{
			scanf("%d",&X[i]);
		}
		for(i=1; i<=n; i++) 
		{
			scanf("%d",&Y[i]);
		}

		printf("Twin Towers #%d\n",test++);
		printf("Number of Tiles : %d\n\n",LCSlength());
	}
}