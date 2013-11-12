#include <stdio.h>

union
{
	long data;
	char bit[4];
}x,y;

void main()
{
	while(scanf("%ld",&x.data)!=EOF)
	{

		y.bit[0]=x.bit[3];
		y.bit[1]=x.bit[2];
		y.bit[2]=x.bit[1];
		y.bit[3]=x.bit[0];

		printf("%ld converts to %ld\n",x.data,y.data);
	}
}
