#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

long a[500];

void main()
{
	long i,j,k,n,Q,R,C,Case=1;

	//freopen("in.txt","r",stdin);
	
	scanf("%ld",&n);

	while(n)
	{
		scanf("%ld %ld",&C,&R);
		Q=C-R;

		printf("Case #%ld:",Case++);

		if(Q==0) printf("0");
		else if(Q<R) printf("");
		else
		{
			k=sqrt(Q);j=0;
			for(i=1; i<=k; i++)
			{
				if(Q%i==0)
				{
					a[j++]=i;
					a[j++]=Q/i;
				}
			}

			sort(a,a+j);

			for(i=0; i<j; i++)
			{
				if(a[i]>R && a[i]!=a[i-1])
				printf(" %ld",a[i]);
			}
		}
		printf("\n");
		n--;
	}
}