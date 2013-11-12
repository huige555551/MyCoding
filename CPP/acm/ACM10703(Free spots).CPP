#include<stdio.h>
#include<string.h>

#define MAX 502

int a[MAX][MAX];

void main()
{
	int i,j,k,W,H,N,x1,x2,y1,y2,x,y;
	long count;

	//freopen("in.txt","r",stdin);

	while(scanf("%d %d %d",&W,&H,&N)==3)
	{
		if(!W && !H && !N) break;

		memset(a,0,sizeof(a));

		for(i=1; i<=N; i++)
		{
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			
			if(x1>x2)
			{ 
				x=x1;
				x1=x2;
				x2=x;
			}
			if(y1>y2)
			{
				y=y1;
				y1=y2;
				y2=y;

			}

			for(j=x1; j<=x2; j++)
			{
				for(k=y1; k<=y2; k++)
				{
					a[j][k]=1;
				}
			}
		}

		count=0;
		for(i=1; i<=W; i++)
		{
			for(j=1; j<=H; j++)
			{
				if(a[i][j]==0)
					count++;
			}
		}

		if(count==0) printf("There is no empty spots.\n");
		else if(count==1) printf("There is one empty spot.\n");
		else printf("There are %ld empty spots.\n",count);
	}
}