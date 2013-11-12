#include<stdio.h>
#include<math.h>

#define pi 2.0*acos(0.0)

void main()
{
	long double a,b,c,t,A,C,r1,r2,area1,area2,area3,ans1,ans2,ans3;

	while(scanf("%Lf %Lf %Lf",&a,&b,&c)==3)
	{
		t=((b*b)+(c*c)-(a*a))/(2.0*b*c);
		A=acos(t);

		t=((a*a)+(b*b)-(c*c))/(2.0*a*b);
		C=acos(t);

		t=(1/tan(A/2.0))+(1/tan(C/2.0));
		r1=b/t;

		area1=pi*(r1*r1);

		area2=0.5*a*b*sin(C);

		t=2.0*sin(A);
		r2=a/t;
		
		area3=pi*(r2*r2);

		ans1=area3-area2;
		ans2=area2-area1;
		ans3=area1;

		printf("%.4Lf %.4Lf %.4Lf\n",ans1,ans2,ans3);
	}
}