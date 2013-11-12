#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef long long big;

char s[500];
char t[100];
big a[100],b[100],index_a,index_b;

void process_t()
{
	big i,j,l,r,n,m;
	char p[50];

	l=strlen(t);

	r=n=m=0;
	for(i=0; i<l; i++)
	{
		j=0;
		while((t[i]>='0' && t[i]<='9') && i<l)
		{
			p[j++]=t[i++];
		}
		p[j]=0;

		++index_a;
		n=atol(p);
		a[index_a]=n;

		if(t[i]=='/')
		{
			i++;
			j=0;
			while(t[i]>='0' && t[i]<='9' && i<l)
			{
				p[j++]=t[i++];
			}
			p[j]=0;
			m=atol(p);

			a[index_a]=n;
			b[++index_b]=m;
		}
		else if(t[i]=='-')
		{
			i++;
			j=0;
			while(t[i]!='/')
			{
				p[j++]=t[i++];
			}
			p[j]=0;
			r=atol(p);

			i++;
			j=0;
			while(t[i]>='0' && t[i]<='9' && i<l)
			{
				p[j++]=t[i++];
			}
			p[j]=0;
			m=atol(p);

			a[index_a]=(n*m)+r;
			b[++index_b]=m;
		}
		else;
	}
}

void get_num()
{
	big i,j,l;

	l=strlen(s);

	for(i=0; i<l; i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			j=0;
//			while(s[i]!=' '&& i<l)
			while( ((s[i]>='0' && s[i]<='9')||(s[i]=='-')||(s[i]=='/')) && i<l )
			{
				t[j++]=s[i++];
			}
			t[j]=0;
			process_t();
		}		
	}
}

big gcd(big x,big y)
{
	big dividend,divisor,remainder=1,g;

	dividend=x>y?x:y;
	divisor=x>y?y:x;

	while(remainder)
	{
		remainder=dividend%divisor;

		dividend=divisor;
		divisor=remainder;
	}

	g=dividend;

	return g;
}

void main()
{
	big n,i,m,g,r;
	int test;

	//freopen("in.txt","r",stdin);

	gets(s);
	test=atoi(s);

	while(test)
	{
		gets(s);

		for(i=0; i<=index_a; i++) a[i]=0;
		for(i=0; i<=index_b; i++) b[i]=0;

		index_a=-1;
		index_b=-1;

		get_num();

		n=1;
		for(i=0; i<=index_a; i++)
		{
			n*=a[i];
			if(n==0) break;
		}
		if(index_a==-1) n=0;

		m=1;
		for(i=0; i<=index_b; i++)
		{
			m*=b[i];
			if(m==0) break;
		}
		if(index_b==-1) m=0;

		if(m!=0 && m!=1 && n!=0)
		{
			g=gcd(n,m);

			n=n/g;
			m=m/g;

			if(m!=1)
			{
				if(n<m)
					printf("%lld/%lld\n",n,m);
				else if(n>m)
				{
					r=n/m;
					n=n%m;
					m=m;	

					printf("%lld-%lld/%lld\n",r,n,m);
				}
				else printf("1\n");
			}
			else printf("%lld\n",n);
		}
		else
			printf("%lld\n",n);

		test--;
	}
}