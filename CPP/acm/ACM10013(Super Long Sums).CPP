#include<stdio.h>

void main()
{
	int num[1000002][2];
	int i,count,no_of_dgt;

	scanf("%d",&count);

	while(count)
	{
		scanf("%d",&no_of_dgt);

		for(i=0; i<no_of_dgt; i++)
		{
			scanf("%d%d",&num[i][0],&num[i][1]);
		}

		for(i--; i>=0; i--)
		{
			if(num[i][0] + num[i][1] >=10)
			{
				num[i][0] = num[i][0] + num[i][1] - 10;
				num[i-1][0]=num[i-1][0] + 1;
			}
			else
				num[i][0] = num[i][0] + num[i][1];
		}

		for(i=0; i<no_of_dgt; i++)
		{
			printf("%d",num[i][0]);
		}

		printf("\n");

		count--;

		if(count)
			printf("\n");
	}
}