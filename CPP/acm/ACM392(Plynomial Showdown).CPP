#include<stdio.h>

void main()
{
	int cons[100];
	int i,j;

	while(scanf("%d %d %d %d %d %d %d %d %d",&cons[0],&cons[1],&cons[2],&cons[3],&cons[4],&cons[5],&cons[6],&cons[7],&cons[8])==9)
	{
		j=0;

		for(i=0; i<9; i++)
		{
			if(cons[i]!=0)
			{
				if(cons[i]>0 && j!=0)
				{
					printf(" + ");
				}

				if(cons[i]<0 && j!=0)
				{
					printf(" - ");
					cons[i]=-cons[i];
				}

				if((8-i)!=0)
				{
					if(cons[i]!=1)
					{
						if(cons[i]==-1)
							printf("-");
						else
							printf("%d",cons[i]);
					}

					printf("x");

					if((8-i)!=1)
						printf("^%d",8-i);
				}

				if(i==8)
					printf("%d",cons[i]);

				j=1;
			}
		}
		if(j==0)
			printf("0");

		printf("\n");
	}
}