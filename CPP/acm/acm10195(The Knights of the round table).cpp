#include<stdio.h>
#include<math.h>

void main()
{
	double a,b,c,t,s,r;

	while(scanf("%lf %lf %lf",&a,&b,&c)==3)
	{
		if(a==0.0 || b==0.0 || c==0.0) printf("The radius of the round table is: 0.000\n");
		else
		{
			s=(a+b+c)/2.0;
			t=sqrt(s*(s-a)*(s-b)*(s-c));
			r=t/s;

			printf("The radius of the round table is: %.3lf\n",r);
		}
	}
}