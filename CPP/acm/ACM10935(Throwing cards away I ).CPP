#include<stdio.h>

int a[51][51],stack[150];

void func(int n)
{
	int top,end,i,j;

	top=0; end=n-1;

	i=0;
	while(end-top>1)
	{
		a[n][i++]=stack[top];
		top++;
		stack[end+1]=stack[top];
		end++;
		top++;
	}
	a[n][i++]=stack[top];
	a[n][i]=stack[end];

	/*
	printf("Stack %d: ",n);
	for(j=0; j<=i; j++)
	{
		printf("%d ",a[n][j]);
	}
	printf("\n");
	*/
}

void main()
{
	int i,j,k,n;

	for(i=2; i<=50; i++)
	{
		for(j=1,k=0; j<=i; k++,j++)
		{
			stack[k]=j;
		}
		func(i);
	}

	while(scanf("%d",&n)==1)
	{
		if(n==0) break;

		else if(n>=2)
		{
			printf("Discarded cards:");
			for(i=0; i<n-1; i++)
			{
				printf(" %d",a[n][i]);
				if(i!=n-2) printf(",");
			}
			printf("\n");
		
			printf("Remaining card: %d\n",a[n][i]);
		}
		else
		{
			printf("Discarded cards:\n");
			printf("Remaining card: 1\n");
		}
	}
}