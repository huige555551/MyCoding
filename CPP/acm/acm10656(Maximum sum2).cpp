#include<stdio.h>

int a[1000];

void main()
{
	int n,i,atleast;

	while(scanf("%ld",&n)==1 && n!=0)
	{
		for(i=0; i<n; i++)	
		{
			scanf("%d",&a[i]);
		}

		atleast=0;
		for(i=0; i<n; i++)
		{
			if(a[i])
			{
				printf("%d ",a[i]);
				atleast=1;
			}			
		}
		if(!atleast)
		{
			printf("0");
		}
		printf("\n");
	}
}