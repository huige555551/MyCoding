#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define pi 2*acos(0.0)

void main()
{
	int n,i;
	double a,b,area;
	char s[100];

	//freopen("in.txt","r",stdin);

	gets(s);
	n=atoi(s);

	while(n)
	{
		gets(s);
		i=sscanf(s,"%lf %lf",&a,&b);

		if(i==1)
		{
			area=(pi*a*a)/8.0;
		}
		else
		{
			area=2.0*pi*a*b;
		}

		printf("%0.4lf\n",area);

		n--;
	}
}