#include<stdio.h>
#include<string.h>

#define R 100
#define P 10000

double x1[R],x2[R],y1[R],y2[R],x[P],y[P];

void main()
{
	int i,j,r,p,rec=1,contain;
	char s[100];

	freopen("in.txt","r",stdin);

	r=p=0;
	while(gets(s))
	{
		if(strcmp(s,"*")==0) {rec=0;continue;}

		if(rec)
		{
			sscanf(s,"%*c %lf %lf %lf %lf",&x1[r],&y1[r],&x2[r],&y2[r]);
			r++;
		}
		else
		{
			sscanf(s,"%lf %lf",&x[p],&y[p]);
			p++;
		}
	}
	p--;

	for(i=0; i<p; i++)
	{
		contain=0;
		for(j=0; j<r; j++)
		{
			if( ((x[i]<x1[j] && x[i]>x2[j]) || (x[i]>x1[j] && x[i]<x2[j])) && ( ((y[i]<y1[j] && y[i]>y2[j]) || (y[i]>y1[j] && y[i]<y2[j])) ))
			{
				printf("Point %d is contained in figure %d\n",i+1,j+1);
				contain=1;
			}
		}
		if(!contain)
		{
			printf("Point %d is not contained in any figure\n",i+1);
		}
	}
}