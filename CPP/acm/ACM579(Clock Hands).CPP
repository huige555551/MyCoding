#include<stdio.h>
#include<math.h>

void main()
{
	int H,M;
	double a,b,angle;

	while(scanf("%d:%d",&H,&M)!=EOF)
	{
		if(H==0 && M==0) break;

		a=(H*30.0)+(M*0.5);
		b=M*6.0;

		angle=fabs(a-b);

		if(angle>180.0)
			angle=360.0-angle;

		printf("%.3lf\n",angle);
	}
}