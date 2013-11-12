#include<stdio.h>
#include<string.h>
#include<math.h>

#define F 100

struct rectangle
{
	double x1,y1,x2,y2;
}rec[100];
struct circle
{
	double x,y,r;
}cir[100];
struct triangle
{
	double x1,x2,x3,y1,y2,y3;
}tri[100];

char ch[F];

double area(double x1,double x2,double x3,double y1,double y2,double y3)
{
	return (x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2))/2.0;
}

int check(double x,double y,int i)
{
	double a1,a2,a3,a4;

	a1=fabs(area(tri[i].x1,tri[i].x2,x,tri[i].y1,tri[i].y2,y));
	a2=fabs(area(tri[i].x1,tri[i].x3,x,tri[i].y1,tri[i].y3,y));
	a3=fabs(area(tri[i].x2,tri[i].x3,x,tri[i].y2,tri[i].y3,y));
	a4=fabs(area(tri[i].x1,tri[i].x2,tri[i].x3,tri[i].y1,tri[i].y2,tri[i].y3));

	if(a1+a2+a3-a4<.01) return 1;
	return 0;
}

void main()
{
	int i,j,k,l,r,fig,c,p,t,contain;
	double x,y;
	char s[100];

	//freopen("in.txt","r",stdin);

	r=fig=c=t=0;
	while(gets(s))
	{
		if(strcmp(s,"*")==0) break;

		else if(s[0]=='r')
		{
			sscanf(s,"%c %lf %lf %lf %lf",&ch[fig],&rec[r].x1,&rec[r].y1,&rec[r].x2,&rec[r].y2);
			r++;
		}
		else if(s[0]=='c')
		{
			sscanf(s,"%c %lf %lf %lf",&ch[fig],&cir[c].x,&cir[c].y,&cir[c].r);
			c++;
		}
		else
		{
			sscanf(s,"%c %lf %lf %lf %lf %lf %lf",&ch[fig],&tri[t].x1,&tri[t].y1,&tri[t].x2,&tri[t].y2,&tri[t].x3,&tri[t].y3);
			t++;
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
		for(i=j=k=l=0; i<fig; i++)
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
			else if(ch[i]=='c')
			{
				if( ((x-cir[k].x)*(x-cir[k].x) + (y-cir[k].y)*(y-cir[k].y)) < ( cir[k].r*cir[k].r ) )
				{
					printf("Point %d is contained in figure %d\n",p,i+1);
					contain=1;
				}
				k++;
			}
			else
			{
				if(check(x,y,l))
				{
					printf("Point %d is contained in figure %d\n",p,i+1);
					contain=1;
				}
				l++;
			}
		}
		if(!contain)
		{
			printf("Point %d is not contained in any figure\n",p);
		}
	}
}