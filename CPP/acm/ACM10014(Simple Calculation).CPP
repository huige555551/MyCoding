#include<stdio.h>

void main()
{
	double a1,a0,an1,c,csum;
	int i,n,testcase;

	//freopen("in.txt","r",stdin);

	scanf("%d",&testcase);

	while(testcase)
	{
		scanf("%d",&n);
		scanf("%lf %lf",&a0,&an1);

		csum=0;
		for(i=0; i<n; i++)
		{
			scanf("%lf",&c);
			csum+=c*(n-i);
		}

		a1=( (n*a0)+an1-2*csum ) / (n+1.0);

		printf("%.2lf\n",a1);

		testcase--;
	}
}

/*
Formula derivation:

a1=(a0+a2)/2 - c1
a2=(a1+a3)/2 - c2
a3=(a2+a4)/2 - c3

6a1 = 3a0 + 3a2 - 6c1
4a2 = 2a1 + 2a3 - 4c2
2a3 =  a2 +  a4 - 2c3
---------------------
4a1 = 3a0 +  a4 - 2(c3 + 2c2 +3c3)

Formula:
(n+1)a1 = (n*a0) + an1 -2*(cn +....+ (n-1)c2 + nc1) 

*/