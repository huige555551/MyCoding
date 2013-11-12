//1.first sort 2.find median 3.calculate distance from median .that's all

#include<stdio.h>
#include<math.h>
#include<values.h>

long v[501];

void main()
{
	long test,n,s,d,min,i,j;

	//freopen("in.txt","r",stdin);

	scanf("%ld",&test);

	while(test)
	{
		scanf("%ld",&n);

		for(i=0; i<n; i++)
		{
			scanf("%ld",&v[i]);
		}

		min=MAXLONG;
		for(i=0; i<n; i++)
		{
			d=0;
			for(j=0; j<n; j++)
			{
				d+=labs(v[i]-v[j]);
			}
			if(min>d)
			{
				min=d;
			}
		}

		printf("%ld\n",min);

		test--;
	}
}