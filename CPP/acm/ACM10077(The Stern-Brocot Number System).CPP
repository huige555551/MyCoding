#include<stdio.h>
#include<math.h>

void main()
{
	double m1,n1,m2,n2,m,n,i,j,d;

	while(scanf("%lf %lf",&i,&j)==2)
	{
		if(i==1 && j==1) break;

		m1=0; m=1; m2=1;
		n1=1; n=1; n2=0;

		d=i/j;

		while(1)
		{
			if(fabs(d-(m/n))<1e-9)
			{
				printf("\n");
				break;
			}
			else if(d<(m/n))
			{
				printf("L");
				m2=m; n2=n;
				m=m1+m;
				n=n1+n;
			}
			else if(d>(m/n))
			{
				printf("R");
				m1=m; n1=n;
				m=m+m2;
				n=n+n2;
			}
		}
	}
}