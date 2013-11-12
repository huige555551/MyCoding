#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

void main()
{
	double d = 0;
	long x,X,y,Y,t,test;
	char s[200];

	//freopen("in.txt","r",stdin);

	gets(s);
	test=atol(s);
	gets(s);

	while(test)
	{
		gets(s);

		//while (4 == scanf("%d%d%d%d",&x,&y,&X,&Y))
		d=0;
		while(gets(s))
		{
			if(strcmp(s,"")==0) break;
			sscanf(s,"%ld %ld %ld %ld",&x,&y,&X,&Y);
			//d += hypot(x-X,y-Y);
			d+=sqrt((x-X)*(x-X)+(y-Y)*(y-Y));
		}

		t = (((d/1000)*2)/20)*60+.5;

		printf("%ld:%0.2ld\n",t/60,t%60);

		test--;
		if(test) printf("\n");
	}
}