#include<stdio.h>

void main()
{
	long double i,k,sum1,sum2,count;

	count=sum1=0;
	sum2=2;

	for(i=2,k=3; ;i++)
	{
		sum1=sum1+i-1;

		sum2=sum2-i;

		for(; sum2<=sum1; k++)
		{
			sum2=sum2+k;
		}

		if(sum2-(k-1)==sum1)
		{
			count++;

			printf("%10.0Lf%10.0Lf\n",i,k-2);

			if(count==10)
				break;
		}
	}
}