#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;

long a[10000];

void main()
{
	long n,m,i,j,p,sum,num,test=1,min;

	freopen("in.txt","r",stdin);

	while(scanf("%ld",&n)==1)
	{
		if(n==0) break;

		for(i=0; i<n; i++)
		{
			scanf("%ld",&a[i]);
		}

		sort(a,a+n);

		scanf("%ld",&m);

		printf("Case %ld:\n",test++);

		while(m)
		{
			min=2147483647;
			scanf("%ld",&p);

			for(i=0; i<n; i++)
			{
				for(j=i+1; j<n; j++)
				{
					if(a[i]!=a[j])
					{
						sum=labs(p-(a[i]+a[j]));
						if(sum<min)
						{
							min=sum;
							num=a[i]+a[j];
							if(min==0) break;
						}
					}
				}
				if(min==0) break;
			}

			printf("Closest sum to %ld is %ld.\n",p,num);

			m--;
		}
	}
}