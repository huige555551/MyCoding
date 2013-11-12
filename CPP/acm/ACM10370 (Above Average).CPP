#include<stdio.h>

void main()
{
	int count,n,p[1000],sum=0;
	int i,j;
	double avg_num,avg_std;

	scanf("%d",&count);

	for(i=0; i<count; i++)
	{
		int std=0;
		sum=0;

		scanf("%d",&n);

		for(j=0; j<n; j++)
		{
			scanf("%d",&p[j]);
			sum=sum+p[j];
		}

		avg_num=(double)sum/n;

		for(j=0; j<n; j++)
		{
			if(p[j] > avg_num)
			{
				std++;
			}
		}

		avg_std=((double)std/n)*100;

		printf("%.3f%\n",avg_std);
	}
}