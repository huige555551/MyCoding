#include<stdio.h>
#include<math.h>

#define pi 2*acos(0.0)

void main()
{
	double r1,r2,d,w,s,h1,h2,v1,v2,a1,a2,v,a,density;
	int n;

	//freopen("in.txt","r",stdin);

	scanf("%d",&n);

	while(n)
	{
		scanf("%lf %lf %lf %lf %lf",&r1,&r2,&d,&w,&s);

		h1=((r1*r1)-(r2*r2)+(d*d))/(2.0*d);
		h2=d-h1;
		v1=((2*pi*r1*r1*r1)/3.0) + (pi*r1*r1*h1) - ((pi*h1*h1*h1)/3.0);
		v2=((2*pi*r2*r2*r2)/3.0) + (pi*r2*r2*h2) - ((pi*h2*h2*h2)/3.0);
		v=v1+v2;

		a1=(2.0*pi*r1*r1)+(2.0*pi*r1*h1);
		a2=(2.0*pi*r2*r2)+(2.0*pi*r2*h2);
		a=a1+a2;

		printf("%0.4lf %0.4lf\n",v,a);

		density=w/v;

		if(density>s)
		{
			printf("The Paired-Sphere Sinks.\n");
		}
		else
			printf("The Paired-Sphere Floats.\n");

		n--;
	}
}