#include<stdio.h>
#include<math.h>

void main()
{
	int invalid,n;
	double A,B,C,Ha,Hb,Hc,X,t;

	//freopen("in.txt","r",stdin);

	scanf("%d",&n);

	while(n)
	{
		scanf("%lf %lf %lf",&Ha,&Hb,&Hc);

		invalid=1;

		if(Ha>0.0 && Hb>0.0 && Hc>0.0)
		{
			A=1.0/Ha;
			B=1.0/Hb;
			C=1.0/Hc;

			t=(A+B+C)*(-A+B+C)*(A-B+C)*(A+B-C);

			if(t>0.0)
			{
				X=sqrt(1.0/t);
				invalid=0;
			}
		}
		if(invalid)
		{
			printf("These are invalid inputs!\n");
			n--;
		}
		else 
			printf("%.3lf\n",X);	
	}
}