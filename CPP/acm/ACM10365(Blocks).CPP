#include<stdio.h>
#include<values.h>
#include<math.h>

void main()
{
	long i,j,k,n,test,t,v,area,min=0;

	//freopen("in.txt","r",stdin);

	scanf("%ld",&test);

	while(test)
	{
		scanf("%ld",&n);

		t=sqrt(n);min=MAXLONG;
		for(i=1; i<=t; i++)
		{
			for(j=1; j<=t; j++)
			{
				for(k=1; k<=n; k++)
				{
					v=i*j*k;
					if(v==n)
					{
						area=2*( (i*j) + (j*k) + (k*i) );
						if(area<min) min=area;
					}
					else if(v>n) break;
				}
			}
		}

		printf("%ld\n",min);

		test--;
	}
}