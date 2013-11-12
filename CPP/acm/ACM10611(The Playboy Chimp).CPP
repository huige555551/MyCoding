#include<stdio.h>

#define MAX 50002

long a[MAX];

void main()
{
	long n,i,j,q,low,high,mid,t,b;

	freopen("in.txt","r",stdin);

	scanf("%ld",&n);

	for(i=j=1; i<=n; i++)
	{
		scanf("%ld",&t);
		if(t!=a[j-1])
		{
			a[j]=t;
			j++;
		}
	}
	n=j-1;

	scanf("%ld",&q);

	for(i=1; i<=q; i++)
	{
		scanf("%ld",&b);

		low=1;
		high=n;

		while(low<=high)
		{
			mid=(low+high)/2;

			if(b==a[mid])
			{
				if(mid<n && mid>1)
				{
					printf("%ld %ld\n",a[mid-1],a[mid+1]);
				}
				else if(mid==n)
				{
					printf("%ld X\n",a[mid-1]);
				}
				else
				{
					printf("X %ld\n",a[mid+1]);
				}
				break;
			}
			else if(b<a[mid])
			{
				high=mid-1;
			}
			else
			{
				low=mid+1;
			}
		}
		if(low>high)
		{
			if(low<=n && high>=1)
			{
				printf("%ld %ld\n",a[high],a[low]);
			}
			else if(b>a[n])
			{
				printf("%ld X\n",a[n]);
			}
			else
			{
				printf("X %ld\n",a[1]);
			}
		}
	}
}
