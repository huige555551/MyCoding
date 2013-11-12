//acm575-skew binary
//22/8/05

#include<stdio.h>
#include<string.h>
#include<math.h>

long skew_binary(char ch[]);

void main()
{
	char ch[80];

	while(1)
	{
		gets(ch);
		if(ch[0]=='0'&&ch[1]==0) break;
		printf("%ld\n",skew_binary(ch));
	}
}

long skew_binary(char ch[])
{
	long n=0;
	int i,k;

	for(i=0,k=strlen(ch); i<strlen(ch); i++,k--)
	{
		n+=(ch[i]-'0')*(pow(2,k)-1);
	}

	return n;
}