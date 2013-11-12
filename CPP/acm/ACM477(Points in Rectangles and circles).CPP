#include<stdio.h>
#include<string.h>

#define F 100

struct rectangle
{
	double x1,y1,x2,y2;
}rec[100];
struct circle
{
	double x,y,r;
}cir[100];

char ch[F];

void main()
{
	int i,j,k,r,fig,c,p,contain;
	double x,y;
	char s[100];

	//freopen("in.txt","r",stdin);

	r=fig=c=0;
	while(gets(s))
	{
		if(strcmp(s,"*")==0) break;

		else if(s[0]=='r')
		{
			sscanf(s,"%c %lf %lf %lf %lf",&ch[fig],&rec[r].x1,&rec[r].y1,&rec[r].x2,&rec[r].y2);
			r++;
		}
		else
		{
			sscanf(s,"%c %lf %lf %lf",&ch[fig],&cir[c].x,&cir[c].y,&cir[c].r);
			c++;
		}
		fig++;
	}

	p=0;
	while(gets(s))
	{
		sscanf(s,"%lf %lf",&x,&y);
		p++;

		if(x==9999.9 && y==9999.9) break;

		contain=0;
		for(i=j=k=0; i<fig; i++)
		{
			if(ch[i]=='r')
			{
				if( ((x<rec[j].x1 && x>rec[j].x2) || (x>rec[j].x1 && x<rec[j].x2)) &&  ((y<rec[j].y1 && y>rec[j].y2) || (y>rec[j].y1 && y<rec[j].y2)) )
				{
					printf("Point %d is contained in figure %d\n",p,i+1);	
					contain=1;
				}
				j++;
			}
			else
			{
				if( ((x-cir[k].x)*(x-cir[k].x) + (y-cir[k].y)*(y-cir[k].y)) < ( cir[k].r*cir[k].r ) )
				{
					printf("Point %d is contained in figure %d\n",p,i+1);
					contain=1;
				}
				k++;
			}
		}
		if(!contain)
		{
			printf("Point %d is not contained in any figure\n",p);
		}
	}
}