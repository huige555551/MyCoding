#include<stdio.h>
#include<math.h>

long binomial(int n,int m)
{
	int k;
	register int i,j;
	double c,d;

	c=d=1;
	k=(m>(n-m))?m:(n-m);
	for(j=1,i=k+1;(i<=n);i++,j++)
	{
		c*=i;
		d*=j;
		if( !fmod(c,d)  && (d!=1) )
		{	c/=d;
			d=1;
		}
	}

	return (long)c;
}

/* A sample main function */
void main(void)
{
	int n,k;

	while(1){
		scanf("%d%d",&n,&k);
		if(n==0 && k==0) break;
		printf("%ld\n",binomial(n,k));
	}
}

