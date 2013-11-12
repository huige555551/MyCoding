#include<stdio.h>

#define MAX 10000

int block[MAX+1];

void main()
{
	int left,height,right;
	int i,max_right=0;

	freopen("input.txt","r",stdin);

	while(scanf("%d %d %d",&left,&height,&right)==3)
	{
		for(i=left; i<right; i++)
		{
			if(block[i] < height)
			{
				block[i]=height;
			}
		}

		if(max_right < right)
		{
			max_right=right;
		}
	}

	for(i=1; i<=max_right; i++)
	{
		if(block[i]!=block[i-1])
		{
			printf("%d %d",i,block[i]);

			if(i<max_right)
				printf(" ");
		}
	}
}

