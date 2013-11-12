#include<stdio.h>
#include<math.h>

void main()
{
	double u,v,w,s,x,y,z;

	while(scanf("%lf %lf %lf",&u,&v,&w)==3)
	{
		s=(u+v+w)/2.0;

		if(s>u && s>v && s>w)
		{
			x=s*(s-u)*(s-v)*(s-w);
			y=sqrt(x);
			z=(4.0*y)/3.0;

			printf("%0.3lf",z);
		}
		else 
			printf("-1.000");

		printf("\n");
	}
}