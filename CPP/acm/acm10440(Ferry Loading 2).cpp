#include<stdio.h>

int leave[2000];

void main()
{
	int test,n,t,m,i,f,k,ntrip;
	
	//freopen("in.txt","r",stdin);
	
	scanf("%d",&test);

	while(test--)
	{
		scanf("%d %d %d",&n,&t,&m);

		t=t*2;                   //for acrossing 2 times in every trip
		ntrip = (m+n-1)/n;       //upper bound of (m/n) = no_of_trip
		k = m-(ntrip-1)*n;  //no_of_car_in_fist_trip, it can be less than n

		for(i=1; i<=k; i++)
		{	//handling less than n cars in a trip 
			scanf("%d",&leave[0]);  //store the time of last car's arrival of first trip
		}

		for(f=1; f<ntrip; f++)
		{
			for(i=1; i<=n; i++)
			{
				scanf("%d",&leave[f]);
			}
		}

		for(f=0; f<ntrip-1; f++)
		{
			if( (leave[f]+t) > (leave[f+1]) )
			{
				leave[f+1] = leave[f]+t;
			}
		}

		printf("%d %d\n",leave[ntrip-1]+t/2,ntrip);
	}
}