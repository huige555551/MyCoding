#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main()
{
	char s[10000],p[4];
	int i,n;

	while(gets(s)!=NULL)
	{    /*encoding*/
		if(!(s[0]>='0'&&s[0]<='9'))
		{
			for(i=strlen(s)-1; i>=0; i--)
			{
				n=s[i];
				while(n)
				{
					printf("%d",n%10);
					n=n/10;
				}
			}
		}
		else /*decoding*/
		{
			i=strlen(s)-1;
			while(i>=0)
			{
				if(s[i]=='1')
				{
					p[0]=s[i];
					p[1]=s[i-1];
					p[2]=s[i-2];
					p[3]=0;
					i=i-3;
				}
				else
				{
					p[0]=s[i];
					p[1]=s[i-1];
					p[2]=0;
					i=i-2;
				}
				n=atoi(p);
				printf("%c",n);
			}
		}
		printf("\n");
	}
}