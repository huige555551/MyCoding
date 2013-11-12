#include<stdio.h>

#define INF 2147483647
#define MAX 1000

long m[MAX][MAX];
int s[MAX][MAX],r[MAX],c[MAX];

void print(int i,int j)
{
	if(i==j)
		printf("A%d",i);
	else
	{ 
		printf("(");
		print(i,s[i][j]);
		printf(" x ");
		print(s[i][j]+1,j);
		printf(")");
	}
}

void main()
{
	long q;
	int n,i,j,k,l,test=1;

	//freopen("in.txt","r",stdin);

	while(scanf("%d",&n)==1)
	{
		if(n==0) break;

		for(i=1; i<=n; i++)
		{
			scanf("%d %d",&r[i],&c[i]);
		}

		for(i=1; i<=n; i++)
		{
			m[i][i]=0;
		}

		for(l=2; l<=n; l++)
		{
			for(i=1; i<=n-l+1; i++)
			{
				j=i+l-1;

				m[i][j]=INF;

				for(k=i; k<=j-1; k++)
				{
					q=m[i][k]+m[k+1][j]+r[i]*c[k]*c[j];
					
					if(q<m[i][j])
					{
						m[i][j]=q;	
						s[i][j]=k;
					}
				}
			}
		}

		printf("Case %d: ",test++);
		print(1,n);
		printf("\n");
	}
}