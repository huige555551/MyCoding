/*STRANGE:: IF ONLY MATH.H THEN RUNTIME ERROR*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

long gcd(long x,long y)
{
	long dividend,divisor,remainder=-1,gcd;

	dividend=x>y?x:y;
	divisor=x>y?y:x;

	while(remainder)
	{
		remainder=dividend%divisor;

		dividend=divisor;
		divisor=remainder;
	}

	gcd=dividend;

	return gcd;
}

void main()
{
	long a,b,c,i,j,k,cage=1;
	double n,x;
	char s[20];

	/*freopen("332.in","r",stdin);*/

	while(1)
	{
		scanf("%ld",&j);
		if(j==-1)break;
		scanf("%s",s);
		n=atof(s);

		if(n<1.0)
		{
			x=(double)n*pow(10,j);

			if(x)
			{
				if(s[0]=='0')
				{
					for(k=0; k<strlen(s)-j-2; k++)
					{
						x=x*10;
					}
				}
				else if(s[0]=='.')
				{
					for(k=0; k<strlen(s)-j-1; k++)
					{
						x=x*10;
					}
				}

				if(j)
				{
					a=(long)(pow(10,k+j)*n+0.5) - (long)(pow(10,k)*n);
					b=pow(10,k+j) - pow(10,k);
				}
				else
				{
					a=pow(10,k)*n+0.5;
					b=pow(10,k);
				}

				c=gcd(a,b);

				a=a/c;
				b=b/c;

				printf("Case %ld: %ld/%ld\n",cage++,a,b);

			}
			else
				printf("Case %ld: 0/1\n",cage++);
		}
		else
			printf("Case %ld: 0/1\n",cage++);
	}
}

