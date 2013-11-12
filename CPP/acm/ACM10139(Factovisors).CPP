#include<stdio.h>
#include<math.h>

void main()
{
	long n,m,t,i,j,k,jj;

	freopen("in.txt","r",stdin);

	while(2==scanf("%ld %ld",&n,&m))
	{
		t=m;

        jj=1+sqrt((double)t); 

		for(i=2; i<jj; i++)
		{
			if(t%i==0)
			{
				for(j=0; t%i==0; j++)
				{
					t/=i;
				}

                jj=1+sqrt((double)t);  

				for(k=i; k<=n; k*=i)
				{
					j-=n/k;
				}

				if(j>0)
				{
					printf("%ld does not divide %ld!\n",m,n);
					goto done;
				}
			}
		}
		if(t>n || t==0)
		{
			if(n==0 && t==1) printf("%ld divides %ld!\n",m,n);
			else printf("%ld does not divide %ld!\n",m,n);
		}
		else
		{
			printf("%ld divides %ld!\n",m,n);
		}
		done:;
	}
}