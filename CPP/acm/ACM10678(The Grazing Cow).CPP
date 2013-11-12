#include<stdio.h>
#include<math.h>

void main()
{
	int testcase,D,L;
	double a,b,c;

	freopen("in.txt","r",stdin);

	scanf("%d",&testcase);

	while(testcase)
	{
		scanf("%d %d",&D,&L);

		a=L/2.0;
		b=sqrt( (a*a) - ((D*D)/4.0) );
		c=3.141592653589793*a*b;

		printf("%0.3lf\n",c);

		testcase--;
	}
}