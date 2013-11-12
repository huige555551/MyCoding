#include<stdio.h>

void main()
{
	long double a,b,t;

	while(scanf("%Lf %Lf",&a,&b)!=EOF)
	{
		if(a<b)
		{
			t=a;
			a=b;
			b=t;
		}
		printf("%.0Lf\n",a-b);
	}
}