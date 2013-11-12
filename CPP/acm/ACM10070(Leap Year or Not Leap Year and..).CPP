#include<stdio.h>
#include<string.h>

char a[10000];

void main()
{
	int first=1,mod4,mod100,mod400,mod15,mod55,i,leap,b,h;

	while(scanf("%s",a)!=EOF)
	{
		if(first) first=0;
		else printf("\n");

		mod4=mod100=mod400=mod15=mod55=0;
		leap=h=b=0;

		for(i=0; i<strlen(a); i++)
		{
			mod4=((mod4*10)+a[i]-'0')%4;
			mod100=((mod100*10)+a[i]-'0')%100;
			mod400=((mod400*10)+a[i]-'0')%400;
			mod15=((mod15*10)+a[i]-'0')%15;
			mod55=((mod55*10)+a[i]-'0')%55;
		}

		if( (!mod4 && mod100) || (!mod400))
		{
			printf("This is leap year.\n");
			leap=1;
		}

		if(!mod15)
		{
			printf("This is huluculu festival year.\n");
			h=1;
		}

		if(!mod55 && leap)
		{
			printf("This is bulukulu festival year.\n");
			b=1;
		}

		if(leap==0 && h==0 && b==0) printf("This is an ordinary year.\n");

	}
}