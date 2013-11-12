#include<stdio.h>

void main()
{
	int testcase,n,m,i,j,sum;

	freopen("in.txt","r",stdin);

	scanf("%d",&testcase);

	j=1;
	while(j<=testcase)
	{
		scanf("%d%d",&n,&m);

		sum=0;
		for(i=n; i<=m; i++)
		{
			if( i!=0 && i%2!=0)
			{
				sum=sum+i;
			}
		}

		printf("Case %d: %d\n",j,sum);

		j++;
	}
}