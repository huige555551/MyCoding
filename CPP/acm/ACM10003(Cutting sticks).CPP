#include <stdio.h>
#include<values.h>

#define MAX 60

long p[MAX],m[MAX][MAX];

void main()
{
	long i,j,k,l,q,sum,N,n,x,y,t;

	scanf("%ld",&N);

	while(N)
	{
		scanf("%ld",&n);

		y=0;
		for(i=1; i<=n; i++)
		{
			scanf("%ld",&x);
			p[i]=x-y;
			y=x;
		}
		p[i]=N-y;

		n=i;

		for(i=1; i<=n; i++)
		{
			m[i][i]=0;
		}

		for(l=2; l<=n; l++)
		{
			for(i=1; i<=n-l+1; i++)
			{
				j=l+i-1;

				m[i][j]=MAXLONG;

				y=sum=0;
				for(k=i; k<=j-1; k++)
				{
					q=m[i][k]+m[k+1][j];

					if(!y)
					{
						for(t=i; t<=j; t++)
						{
							sum+=p[t];
							y=1;
						}
					}

					q+=sum;

					if(q<m[i][j])
					{
						m[i][j]=q;
					}
				}
			}
		}

		printf("The minimum cutting is %ld.\n",m[1][n]);

		scanf("%ld",&N);
	}
}
