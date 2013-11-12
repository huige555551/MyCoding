#include<stdio.h>

#define MAX 102

int perfection_check(long num);

void main()
{
	int i,j,value;
	long num[MAX];

	for(i=0; num[i-1]!=0; i++)
	{
		scanf("%ld",&num[i]);
	}

	printf("PERFECTION OUTPUT\n");

	for(j=0; j<i-1; j++)
	{
		value=perfection_check( num[j] );

		if(value==0)
			printf("%5ld  PERFECT\n",num[j]);
		else if(value==1)
			printf("%5ld  ABUNDANT\n",num[j]);
		else if(value==-1)
			printf("%5ld  DEFICIENT\n",num[j]);
	}

	printf("END OF OUTPUT");
}

int perfection_check(long num)
{
	long i;
	long sum=0;

	for(i=1; i<=num/2; i++)
	{
		if(num%i==0)
		{
			sum+=i;
		}
	}

	if(sum==num)
		return 0;

	else if(sum>num)
		return 1;

	else
		return -1;
}