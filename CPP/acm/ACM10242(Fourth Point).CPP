#include<stdio.h>

void main()
{
	double x1,x2,x3,y1,y2,y3,x4,y4,h,k;

	//freopen("in.txt","r",stdin);

	while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4)==8)
	{
		if(x2==x3 && y2==y3)
		{
			h=x1+x4-x2;
			k=y1+y4-y2;

			printf("%.3lf %.3lf\n",h,k);
		}
		else if(x2==x4 && y2==y4)
		{
			h=x1+x3-x2;
			k=y1+y3-y2;

			printf("%.3lf %.3lf\n",h,k);
		}
		else if(x1==x3 && y1==y3)
		{
			h=x2+x4-x3;
			k=y2+y4-y3;

			printf("%.3lf %.3lf\n",h,k);
		}
		else if(x1==x4 && y1==y4)
		{
			h=x2+x3-x1;
			k=y2+y3-y1;

			printf("%.3lf %.3lf\n",h,k);
		}
	}
}

/*
Following are the combination u have to manipulate:
1 2 3 4
a b b c
a b c b
b a b c
b a c b
*/