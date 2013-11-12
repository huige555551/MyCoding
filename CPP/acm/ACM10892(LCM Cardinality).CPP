#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

long a[1000];

long gcd(long a,long b)
{
	while (b > 0)
	{
		a = a % b;
		a ^= b;
		b ^= a;
		a ^= b;
	}

	return a;
}

int isLCM(long r,long s,long n)
{
	long i;

	//r*s will exceed limit
	i=(r/gcd(r,s))*s;

	if(i==n) return 1;
	return 0;
}

void main()
{
	long i,j,k,n,c;

	freopen("in.txt","r",stdin);

	while(scanf("%ld",&n)==1)
	{
		if(n==0) break;
		else if(n==1) printf("1 1\n");
		else 
		{
			k=sqrt(n);j=0;
			for(i=2; i<=k; i++)
			{
				if(n%i==0)
				{
					a[j++]=i;
					if((i*i)!=n) a[j++]=(n/i);
				}
			}

			sort(a,a+j);
		
			c=j+2;
			for(i=0; i<j; i++)
			{
				for(k=i+1; k<j; k++)
				{
					if(isLCM(a[i],a[k],n))
					{
						c++;
					}
				}
			}

			printf("%ld %ld\n",n,c);
		}
	}
}