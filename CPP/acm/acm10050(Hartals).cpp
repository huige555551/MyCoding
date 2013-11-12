#include<stdio.h>

int holiday[3651];
int h[101];

void main()
{
	int i,j,count,test,n,p;

	//freopen("in.txt","r",stdin);

	scanf("%d",&test);

	while(test)
	{
		scanf("%d %d",&n,&p);

		for(i=0; i<=n; i++)
		{ 
			holiday[i]=0;
		}
		for(i=6; i<=n; i+=7)
		{
			holiday[i]=1;
			holiday[i+1]=1;
		}

		for(i=0; i<p; i++)
		{
			scanf("%d",&h[i]);
		}

		count=0;
		for(i=0; i<p; i++)
		{
			for(j=h[i]; j<=n; j+=h[i])
			{
				if(holiday[j]==0)
				{ 
					count++;
					holiday[j]=1;
				}
			}
		}

		printf("%d\n",count);

		test--;
	}
}
