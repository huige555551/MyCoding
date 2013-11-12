//acm-369-COMBINATION

#include<stdio.h>
#include<math.h>

double binomial(int n,int m)
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

	return c;
}


void main()
{
	int n,r;

	while(1){
		scanf("  %d  %d",&n,&r);
		if(n==0 && r==0) break;
		printf("%d things taken %d at a time is %.0lf exactly.\n",n,r,binomial(n,r));
	}
}

