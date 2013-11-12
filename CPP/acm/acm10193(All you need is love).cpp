#include<stdio.h>
#include<string.h>
#include<math.h>

typedef long big;

char s1[32],s2[32];

big bin_to_dec(char *s)
{
	int i,j;
	big n=0;

	for(i=strlen(s)-1,j=0; i>=0; i--)
	{
		n+=(s[i]-'0')*pow(2,j);
		j++;
	}

	return n;
}

big gcd(big x,big y)
{
	big dividend,divisor,remainder=1;

	dividend=x>y?x:y;
	divisor=x>y?y:x;

	while(remainder)
	{
		remainder=dividend%divisor;

		dividend=divisor;
		divisor=remainder;
	}

	return dividend;
}


void main()
{
	int p=1,n;
	big num1,num2,g;

	//freopen("in.txt","r",stdin);

	scanf("%d",&n);

	while(n)
	{
		scanf("%s %s",s1,s2);

		num1=bin_to_dec(s1);
		num2=bin_to_dec(s2);

		g=gcd(num1,num2);

		printf("Pair #%d: ",p++);

		if(g!=1) printf("All you need is love!\n");
		else printf("Love is not all you need!\n");

		n--;
	}
}