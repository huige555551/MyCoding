#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX 400000

struct fraction
{
	long a,b;
}data[MAX];

long gcd(long a,long b)
{
	long max,min,t;

	if(a>b) { max=a; min=b;}
	else {max=b; min=a;}

	while(min)
	{
		t=max%min;
		max=min;
		min=t;
	}

	if(max==1) return 1;
	else return 0;
}

int sort_function(const void *c,const void *d)
{
	fraction * x=(fraction*)c;
	fraction * y=(fraction*)d;

	if( ((double)x->a/(double)x->b) < ((double)y->a/(double)y->b) ) return -1;
	else if(((double)x->a/(double)x->b) > ((double)y->a/(double)y->b)) return 1;
	return 0;
}

void main()
{
	long i,j,n,k,index;

	while(scanf("%ld %ld",&n,&k)==2)
	{
		index=0;
		for(i=1; i<=n; i++)
		{
			for(j=1; j<=n; j++)
			{
				if(i<=j)
				{
					if(gcd(i,j)==1)
					{
						data[index].a=i;
						data[index].b=j;
						index++;
					}
				}
			}
		}

		qsort((void*)data,index,sizeof(data[0]),sort_function);

		printf("%ld/%ld\n",data[k-1].a,data[k-1].b);

	}
}