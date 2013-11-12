#include<stdio.h>
#include<math.h>
#include<string.h>

#define a 2.0*acos(0.0)/180.0

char name[100][31];
double latitude[100],longitude[100];
int index;

int search(char *s)
{
	int i;

	for(i=0; i<index; i++)
	{
		if(strcmp(s,name[i])==0)
			return i;
	}
	return -1;
}

void main()
{
	int i,j;
	double t,u,r;
	char s[100],s1[40],s2[40];

	freopen("in.txt","r",stdin);

	i=0;
	while(gets(s))
	{
		if(strcmp(s,"#")==0) break;

		sscanf(s,"%s %lf %lf",name[i],&latitude[i],&longitude[i]);
		i++;
	}
	index=i;

	while(gets(s))
	{
		if(strcmp(s,"# #")==0) break;
		
		sscanf(s,"%s %s",s1,s2);

		printf("%s - %s\n",s1,s2);

		i=search(s1);
		if(i!=-1)	j=search(s2);

		if(i==-1 || j==-1)
		{ 
			printf("Unknown\n");
			continue;
		}

		t=sin(latitude[i]*a)*sin(latitude[j]*a);
		u=cos(latitude[i]*a)*cos(latitude[j]*a)*cos(longitude[i]*a-longitude[j]*a);

		r=(acos(t+u))*6378.0;

		printf("%d km\n\n",long(r+0.5));		
	}	
}