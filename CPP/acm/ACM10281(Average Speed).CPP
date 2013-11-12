#include<stdio.h>
#include<string.h>

void main()
{
	char s[100];
	int hour,min,sec,i,v,prev_h=0,prev_m=0,prev_s=0,prev_v=0,ds,dm,dh;
	double d=0;

	//freopen("in.txt","r",stdin);

	while(gets(s))
	{
		if(strcmp(s,"")==0) continue;
		i=sscanf(s,"%d:%d:%d %d",&hour,&min,&sec,&v);

		ds=sec-prev_s;
		if(ds<0)
		{
			ds+=60;
			prev_m+=1;
		}
		dm=min-prev_m;
		if(dm<0)
		{
			dm+=60;
			prev_h+=1;
		}
		dh=hour-prev_h;

		if(prev_v!=0)
		{
			d+= ((prev_v*ds)/3600.0)+((prev_v*dm)/60.0)+(prev_v*dh);
		}

		if(i==4)
		{
			prev_v=v;
		}
		else
		{
			if(hour>9) printf("%d:",hour);
			else printf("0%d:",hour);

			if(min>9) printf("%d:",min);
			else printf("0%d:",min);

			if(sec>9) printf("%d:",sec);
			else printf("0%d",sec);

			printf(" %.2lf km\n",d);
		}
		prev_h=hour;
		prev_m=min;
		prev_s=sec;
	}
}