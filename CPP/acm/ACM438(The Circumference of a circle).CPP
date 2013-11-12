#include<stdio.h>
#include<math.h>

void main()
{
	double r,g,f,c,z,x1,y1,x2,y2,x3,y3,circum;

	while(scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3)==6)
	{
		z=((x1-x2)*(y2-y3)-(x2-x3)*(y1-y2))*2;

		g=((y1-y2)*(x2*x2 + y2*y2 - x3*x3 - y3*y3)
			- (y2-y3)*(x1*x1 + y1*y1 - x2*x2 - y2*y2))/z;

		f=((x2-x3)*(x1*x1 + y1*y1 - x2*x2 - y2*y2)
			-(x1-x2)*(x2*x2 + y2*y2 - x3*x3 - y3*y3))/z;

		c=-(x1*x1 + y1*y1 + 2*g*x1 + 2*f*y1);

		r=sqrt(g*g+f*f-c);

		circum=2*3.141592653589793*r;

		printf("%.2lf\n",circum);
	}
}