#include<stdio.h>
#include<math.h>

void main()
{
	double h,k,r,g,f,c,z,x1,y1,x2,y2,x3,y3;
	while(scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3)==6)
	{
		z=((x1-x2)*(y2-y3)-(x2-x3)*(y1-y2))*2;

		g=((y1-y2)*(x2*x2 + y2*y2 - x3*x3 - y3*y3)
			- (y2-y3)*(x1*x1 + y1*y1 - x2*x2 - y2*y2))/z;

		f=((x2-x3)*(x1*x1 + y1*y1 - x2*x2 - y2*y2)
			-(x1-x2)*(x2*x2 + y2*y2 - x3*x3 - y3*y3))/z;

		c=-(x1*x1 + y1*y1 + 2*g*x1 + 2*f*y1);

		h=-g;
		k=-f;
		r=sqrt(g*g+f*f-c);

/**************************(x-h)^2 + (y-k)^2 = r^2***************************************/
		printf("(x");
		if(h>0){
			printf(" - ");
			printf("%.3lf",h);
		}else{
			printf(" + ");
			printf("%.3lf",-h);
		}
		printf(")^2 + ");

		printf("(y");
		if(k>0){
			printf(" - ");
			printf("%.3lf",k);
		}else{
			printf(" + ");
			printf("%.3lf",-k);
		}
		printf(")^2 = ");

		printf("%.3lf^2\n",r);

/********************** x^2 + y^2 + 2gx + 2fy + c = 0 **************************/

		printf("x^2 + y^2");

		if(g<0){
			printf(" - ");
			printf("%.3lfx",-(2*g));
		}else{
			printf(" + ");
			printf("%.3lfx",2*g);
		}

		if(f<0){
			printf(" - ");
			printf("%.3lfy",-(2*f));
		}else{
			printf(" + ");
			printf("%.3lfy",2*f);
		}

		if(c<0){
			printf(" - ");
			printf("%.3lf",-c);
		}else{
			printf(" + ");
			printf("%.3lf",c);
		}
		printf(" = 0\n\n");
	}
}