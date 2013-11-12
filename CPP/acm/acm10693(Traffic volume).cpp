#include<stdio.h>
#include<math.h>

void main()
{
	double L,f,v,volume;

	while(scanf("%lf %lf",&L,&f)==2)
	{
		if(L==0 && f==0) break;

		v=sqrt(2.0*L*f);
		volume=(v*3600)/(2*L);

		printf("%0.8lf %0.8lf\n",v,volume);
	}
}