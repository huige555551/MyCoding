#include<stdio.h>
#include<math.h>

#define pi 2*acos(0.0)

void main()
{
	double r,n,a,area;

	while(scanf("%lf %lf",&r,&n)==2)
	{
		a=2*pi/n;

		a=(a-pi)/2;

		area=fabs(((r*r)*sin(2*a))/2);

		area*=n;
		
		printf("%.3lf\n",area);
	}
}

/*
First, to avoid stupid precision error, define pi = 2*acos(0.0) !!! 
Then to calculate the area of the polygon, simply divide them into n smaller triangles. 
Based on the given radius r, you can get the height and width of this small triangles 
by trigonometry relation. Finally, calculate the total area of this n triangles :)
*/