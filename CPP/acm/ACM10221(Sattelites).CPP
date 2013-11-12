#include<stdio.h>
#include<string.h>
#include<math.h>

#define pi 3.14159265358979323

void main()
{
	double s,a,S,D,angle;
	char str[40],t[5];

	freopen("in.txt","r",stdin);

	while(gets(str))
	{
		sscanf(str,"%lf %lf %s",&s,&a,t);

		if(strcmp(t,"min")==0)
		{
			a=a/60.0;
		}

		S=(6440+s)*a*pi/180.0;

		angle=(180-a)*pi/360.0;

		D=2*(6440+s)*cos(angle);

		printf("%.6lf %.6lf\n",S,D);
	}
}