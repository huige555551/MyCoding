#include<stdio.h>

#define MAX 5843
#define MIN(a,b) a<b?a:b;

double a[MAX];

void main()
{
	/*freopen ("output1.txt", "w", stdout);*/

	int i,j,n;
	double min,current;

	a[0]=1;

	for(i=0; i<MAX; i++)
	{
		current=a[i];
		min=30000000000;

		for(j=i; ( (j>=0) && (7*a[j]>current) ); j--)
		{
			if(2*a[j]>current)
				min=MIN(min,2*a[j]);

			if(3*a[j]>current)
				min=MIN(min,3*a[j]);

			if(5*a[j]>current)
				min=MIN(min,5*a[j]);

			min=MIN(min,7*a[j]);
		}

		a[i+1]=min;
		/*printf ("\n%.0lf", a[i]);*/
	}

	while(1)
	{
		scanf("%d",&n);

		if(n==0)break;

		printf("The %d",n);

		if(n%10==1)
		{
			if(n%100==11)
				printf("th ");
			else
				printf("st ");
		}

		else if(n%10==2)
		{
			if(n%100==12)
				printf("th ");
			else
				printf("nd ");
		}

		else if(n%10==3)
		{
			if(n%100==13)
				printf("th ");
			else
				printf("rd ");
		}

		else
		{
			printf("th ");
		}

		printf("humble number is %.0lf.\n",a[n-1]);
	}
}

