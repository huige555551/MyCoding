#include<stdio.h>
#include<math.h>

#define pi 2*acos(0.0)

void main()
{
	double P,S;

	//freopen("in.txt","r",stdin);

	while(scanf("%lf",&P)==1)
	{
		S=( (sin((108*pi)/180)) / (sin((63*pi)/180)) ) *P;
		printf("%0.10lf\n",S);
	}
}