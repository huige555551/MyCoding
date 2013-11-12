#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define a_bs(x,y) (x>y)?x-y:y-x

void main()
{
	long long a,b,t,h,min,m,n;
	//__int64 a,b,t,h,min,m,n;

	while(scanf("%lld %lld",&a,&b)==2)
	//while(scanf("%I64d %I64d",&a,&b)==2)
	{
		if(a==b)
		{ 
			//printf("%I64d %I64d 12:00\n",a,b);
			printf("%lld %lld 12:00\n",a,b);
			continue;
		}

		m=43200*(86400-a);
		n=60*(a_bs(a,b));
		t=m/n;

		if((m%n)*2>=n)
			t++;

		if(t>720)
			t=t%720;

		h=t/60;
		min=t-(h*60);
		if(h==0) h=12;


		//printf("%I64d %I64d ",a,b);
		printf("%lld %lld ",a,b);
		
		if(h<10) 
			//printf("0%I64d",h);
			printf("0%lld",h);
		else 
			//printf("%I64d",h);
			printf("%lld",h);

		printf(":");

		if(min<10) 
			//printf("0%I64d",min);
			printf("0%lld",min);
		else 
			//printf("%I64d",min);
			printf("%lld",min);

		printf("\n");
	}
}

/*
Let x be the difference between the two watches after one day (in seconds) 

x = |a-b| 


So the difference between two watches after one second (y) will be 

y = x / 86400 


Both watches will show the same time after the difference between 
their times will be 12h, that is 43200 seconds, so 

t = 43200 / y 


Where t is the real time after which watches will be synchronized. 
First watch goes (86400-a)/86400 times slower than "real time clocks". 
So it will show: 

seconds = t * (86400-a)/86400 = ( (86400-a)*43200 ) / |a-b| 
minutes = ( (86400-a)*43200 ) / ( 60*|a-b| ) 

'minutes' looks like that m/n, what we have to do is to divide 
'm' by 'n' treating them as integers (result will be floor-ed ), 
and then check out if we have to add one to round result good 

if( (m%n)*2 >= n ) 
minutes++; 

*/