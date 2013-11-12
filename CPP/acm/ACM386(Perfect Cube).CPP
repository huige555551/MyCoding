#include<stdio.h>

void main()
{
	long a,b,c,d;
	long a3,b3,c3,d3;

	for(a=6; a<=200; a++)
	{
		a3=a*a*a;
		for(b=2; b<a; b++)
		{
			b3=b*b*b;
			for(c=b; c<a; c++)
			{
				c3=c*c*c;
				for(d=c; d<a; d++)
				{
					d3=d*d*d;
					if(b3+c3+d3==a3)
					{
						printf("Cube = %ld, Triple = (%ld,%ld,%ld)\n",a,b,c,d);
					}
				}
			}
		}
	}
}