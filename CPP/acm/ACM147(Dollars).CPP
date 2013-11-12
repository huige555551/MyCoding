#include<stdio.h>
#include<math.h>

//#define MAX 30001
#define MAX 10001

long long t[MAX];

void main()
{
	int i,j,n;
	double p,coin,taka;

	t[0]=1;

	for(i=5; i<MAX; i=i+5)
		t[i]=t[i]+t[i-5];

	for(i=10; i<MAX; i=i+5)
		t[i]=t[i]+t[i-10];

	for(i=20; i<MAX; i=i+5)
		t[i]=t[i]+t[i-20];

	for(i=50; i<MAX; i=i+5)
		t[i]=t[i]+t[i-50];

	for(i=100; i<MAX; i=i+5)
		t[i]=t[i]+t[i-100];

	for(i=200; i<MAX; i=i+5)
		t[i]=t[i]+t[i-200];

	for(i=500; i<MAX; i=i+5)
		t[i]=t[i]+t[i-500];

	for(i=1000; i<MAX; i=i+5)
		t[i]=t[i]+t[i-1000];

	for(i=2000; i<MAX; i=i+5)
		t[i]=t[i]+t[i-2000];

	for(i=5000; i<MAX; i=i+5)
		t[i]=t[i]+t[i-5000];

	for(i=10000; i<MAX; i=i+5)
		t[i]=t[i]+t[i-10000];

	while(1)
	{
		scanf("%lf",&p);

		if(p==0.00)
			break;

		coin=modf(p,&taka);

		coin=(coin*100)+(taka*100);
		/*here i have to add 0.5 or i could not get accepted*/
		n=(int)(coin+0.5);

		printf("%6.2lf%17lld\n",p,t[n]);
	}
}


/*

#define MAX 6005

long double t[MAX];

void main()
{
	int i,j,n;
	double p,coin,taka;

	t[0]=1;

	for(i=1; i<MAX; i++)
		t[i]=1;

	for(i=2; i<MAX; i++)
		t[i]=t[i]+t[i-2];

	for(i=4; i<MAX; i++)
		t[i]=t[i]+t[i-4];

	for(i=10; i<MAX; i++)
		t[i]=t[i]+t[i-10];

	for(i=20; i<MAX; i++)
		t[i]=t[i]+t[i-20];

	for(i=40; i<MAX; i++)
		t[i]=t[i]+t[i-40];

	for(i=100; i<MAX; i++)
		t[i]=t[i]+t[i-100];

	for(i=200; i<MAX; i++)
		t[i]=t[i]+t[i-200];

	for(i=400; i<MAX; i++)
		t[i]=t[i]+t[i-400];

	for(i=1000; i<MAX; i++)
		t[i]=t[i]+t[i-1000];

	for(i=2000; i<MAX; i++)
		t[i]=t[i]+t[i-2000];

	while(1)
	{
		scanf("%lf",&p);

		if(p==0.00)
			break;

		coin=modf(p,&taka);

		coin=(coin*100)+(taka*100);

		n=(int)(coin/5+0.5);

		printf("%6.2lf%17.0Lf\n",p,t[n]);
	}
}
*/