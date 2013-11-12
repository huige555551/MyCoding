#include<stdio.h>
#include<math.h>

void main()
{
	double a,b,c,d,D,V;

	freopen("in.txt","r",stdin);

	while(scanf("%lf %lf",&D,&V)==2)
	{
		if(D==0 && V==0) break;

		a=D*D*D;
		b=(6.0*V)/3.141592653589793;
		c=a-b;

		d=pow(c,1.0/3.0);

		printf("%0.3lf\n",d);
	}
}