#include<stdio.h>
#include<math.h>
#include<stdlib.h>

long a[3050],b[3050];

void main()
{
	long i,j,n,jolly;

	freopen("in.txt","r",stdin);

	while(scanf("%ld",&n)!=EOF)
	{
		for(i=0; i<=n; i++)
		{
			b[i]=0;
		}

		for(i=0; i<n; i++)
		{
			scanf("%ld",&a[i]);
		}

		for(i=1; i<n; i++)
		{
			j=labs(a[i]-a[i-1]);
			b[j]=1;
		}

		jolly=1;

		for(i=1; i<=n-1; i++)
		{
			if(b[i]==0)
			{
				jolly=0;
				break;
			}
		}

		if(jolly) printf("Jolly\n");

		else if(!jolly) printf("Not jolly\n");
	}
}