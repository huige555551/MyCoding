#include<stdio.h>
#include<math.h>

#define pi 2*acos(0.0)

void main()
{
	double n,A,r,S,O,a;
	int Case=1;

	freopen("in.txt","r",stdin);

	while(scanf("%lf %lf",&n,&A)==2)
	{
		if(n<3) break;

		r=sqrt(fabs((2.0*A)/(n*sin(pi*((2.0/n)-1)))));

		S=pi*(r*r)-A;

		a=sin(pi*((1.0/n)-(1.0/2.0)));

		O=A-(pi*(r*r)*(a*a));

		printf("Case %d: %.5lf %.5lf\n",Case,S,O);
		
		Case++;
	}
}