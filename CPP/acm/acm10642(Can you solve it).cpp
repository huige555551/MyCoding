#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void main()
{
	long test,Case=1,d,x1,y1,x2,y2,p1,p2,t,s1,s2;

	//freopen("in.txt","r",stdin);

	scanf("%ld",&test);

	while(test)
	{
		scanf("%ld %ld %ld %ld",&y1,&x1,&y2,&x2);

		p1=x1+y1;
		t=(p1*(p1+1))/2;
		s1=(p1-x1)+t;

		p2=x2+y2;
		t=(p2*(p2+1))/2;
		s2=(p2-x2)+t;

		d=labs(s2-s1);

		printf("Case %ld: %ld\n",Case++,d);

		test--;
	}
}

/*
1+2+3+4+5+.....+n=n*(n+1)/2;
0 1 3 6 10 15..........
first i get (x+y,0) path
then (x+y-x) kore sum kori.
*/