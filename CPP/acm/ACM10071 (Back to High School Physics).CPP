#include<stdio.h>

void main()
{
	long v,t,s;

	while(scanf("%ld %ld",&v,&t)!=EOF)
	{
		s=2*v*t;
		printf("%ld\n",s);
	}
}

