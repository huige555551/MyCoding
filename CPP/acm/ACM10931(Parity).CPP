#include<stdio.h>
#include<string.h>

char s[40];
int p;

void make_binary(long n)
{
	int i=0;

	p=0;
	while(n)
	{
		s[i]=(n%2)+'0';
		if(s[i]=='1') p++;
		n=n/2;
		i++;
	}
	s[i]=0;
}

void str_rev()
{
	char t;
	int i,j,l;

	l=strlen(s);

	for(i=0,j=l-1; i<l/2; i++,j--)
	{
		t=s[i];
		s[i]=s[j];
		s[j]=t;
	}
}


void main()
{
	long n;

	while(scanf("%ld",&n)==1)
	{
		if(n==0)break;

		make_binary(n);

		str_rev();

		printf("The parity of %s is %d (mod 2).\n",s,p);
	}
}