#include <stdio.h>

#define MAX 100

void main()
{
	int count,n,a[MAX],i,j,t,swap;

	scanf("%d",&count);

	while(count)
	{
		scanf("%d",&n);

		for(i=0; i<n; i++)
		{
			scanf("%d",&a[i]);
		}

		swap=0;
		for(i=1; i<n; i++)
		{
			for(j=0; j<n-i; j++)
			{
				if(a[j]>a[j+1])
				{
					t=a[j];
					a[j]=a[j+1];
					a[j+1]=t;
					swap++;
				}
			}
		}

		printf("Optimal train swapping takes %d swaps.\n",swap);

		count--;
	}
}
