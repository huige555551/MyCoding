#include <stdio.h>

#define MAX 1001

void main()
{
	int n,a[MAX],i,j,t,swap;

	freopen("in.txt","r",stdin);

	while(scanf("%d",&n)==1)
	{
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

		printf("Minimum exchange operations : %d\n",swap);		
	}
}
