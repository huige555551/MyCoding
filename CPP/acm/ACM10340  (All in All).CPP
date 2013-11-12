#include<stdio.h>
#include<string.h>

#define MAX 1000000

void main()
{
	int i,j;
	char s[MAX],x[MAX],y[MAX],z[MAX];

	while(gets(s)!=NULL)
	{

		for(i=0; s[i]!=' ';i++)
			x[i]=s[i];
		x[i]=0;

		for(j=0; s[i]; j++,i++)
			y[j]=s[i];
		y[j]=0;

		for(i=0,j=0; y[j]; j++)
		{
			if(y[j]==x[i])
			{
				z[i]=x[i];
				i++;
			}
		}
		z[i]=0;

		if(!strcmp(x,z))
			printf("Yes\n");
		else
			printf("No\n");
	}
}