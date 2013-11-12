#include<stdio.h>

int a[1000];

void main()
{
	int n,m,i,sum,avg,exg,t;
	double x;

//	freopen("in.txt","r",stdin);

	while(1)
	{
		scanf("%d",&n);
		if(n==0) break;

		sum=0;
		for(i=0; i<n; i++)
		{
			scanf("%lf",&x);
			a[i]= x*100 + 0.5;
			sum=sum+a[i];
		}

		avg=sum/n;
		t=sum%n;

		exg=m=0;
		for(i=0; i<n; i++)
		{
			if(a[i]>avg)
			{
				m++;
				exg+=a[i]-avg;
			}
		}
		if(m>=t) exg-=t;
		else exg-=m;

		printf("$%.2lf\n",double(exg)/100);
	}
}