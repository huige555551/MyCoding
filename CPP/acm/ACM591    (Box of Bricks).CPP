#include<stdio.h>

void main()
{
	int num_stack, move, brick_in_stack[60]={0};
	int i,sum,avg,set=1;

	while(scanf("%d",&num_stack)==1)
	{
		if(num_stack==0)break;

		sum=0;move=0;

		for(i=0; i<num_stack; i++)
		{
			scanf("%d",&brick_in_stack[i]);
			sum=sum+brick_in_stack[i];
		}
		avg=sum/num_stack;

		for(i=0; i<num_stack; i++)
		{
			if(brick_in_stack[i]>avg)
			{
				move+=brick_in_stack[i]-avg;
			}
		}

		printf("Set #%d\n",set);
		printf("The minimum number of moves is %d.\n",move);
		printf("\n");
		set++;
	}

}