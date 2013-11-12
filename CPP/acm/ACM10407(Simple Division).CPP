#include<iostream.h>
#include<stdio.h>
#include<math.h> 

int in[1100]; 

int GCD(int a,int b)
{ 
	int temp; 

	if(!b) return a;

	if(!a) return b;

	do{ 
		temp=a%b;
		a=b;
		b=temp;
	}while(b);

	return a; 
}

void main()
{ 
	int n,i,j,g;

	//freopen("in.txt","r",stdin);

	while(cin>>n&&n)
	{ 
		i=0;
		in[i++]=abs(n);

		while(cin>>n&&n)
			in[i++]=abs(n-in[0]);
		
		g=in[1];

		for(j=2;j<i;j++)
			g=GCD(g,in[j]);

		cout<<g<<endl;
	} 
}

/*
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
using namespace std;

char s[3000];
char word[1002][20];
long a[1002];
long j;

void get_word(char *s)
{
	int i,k;
	
	for(i=0,j=0; i<strlen(s); i++)
	{
		if( (s[i]>='0'&&s[i]<='9') || (s[i]=='-') )
		{
			for(k=0; (s[i]>='0'&&s[i]<='9') || (s[i]=='-'); i++,k++)
			{
				word[j][k]=s[i];
			}
			word[j][k]=0;
			a[j]=atol(word[j]);
			if(a[j]<0) a[j]=labs(a[j])+1;
			i--;
			j++;
		}
	}
}

long gcd(long x,long y)
{
	long dividend,divisor,remainder=1;

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
	long i,g;
	
	freopen("in.txt","r",stdin);

	while(gets(s))
	{
		if(strcmp(s,"0")==0) break;

		get_word(s);
		j--;

		sort(a,a+j);

		g=a[1]-a[0];
		for(i=2; i<j; i++)
		{
			g=gcd(g,a[i]-a[0]);
		}

		printf("%ld\n",g);
	}
}

*/