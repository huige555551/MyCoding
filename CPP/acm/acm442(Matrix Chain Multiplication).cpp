#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 30
#define B 50

long m[MAX],N[MAX],r[MAX],c[MAX],stack[MAX];
char s[200];

void main()
{
	long i,j,k,a,b,sum,error,n,l;
	char ch;

	//freopen("in.txt","r",stdin);

	//scanf("%ld",&n);
	gets(s);
	n=atol(s);

	for(i=1; i<=n; i++)
	{
		//scanf("%c %ld %ld",&ch,&j,&k);
		gets(s);
		sscanf(s,"%c %ld %ld",&ch,&j,&k);
		m[ch-'A'+1]=j; r[ch-'A'+1]=j;
		N[ch-'A'+1]=k; c[ch-'A'+1]=k;
	}
	//while(scanf("%s",s)==1)
	while(gets(s))
	{
		l=strlen(s);

		for(i=1; i<=n; i++)
		{
			r[i]=m[i];
			c[i]=N[i];
		}

		j=sum=error=0;
		for(i=0; i<l && j>=0; i++)
		{
			if(s[i]>='A' && s[i]<='Z')
			{
				stack[++j]=s[i]-'A'+1;
			}
			else if(s[i]=='(')
			{
				stack[++j]=B;
			}
			else if(s[i]==')')
			{
				k=0;
				while(stack[j]!=B)
				{
					k++;
					j--;
				}
				j--;//for removing ( from stack

				if(k==1)
				{
					stack[++j]=stack[j+2];
				}
				else if(k==2)
				{
					a=stack[j+2];
					b=stack[j+3];

					if(c[a]==r[b])
					{
						sum+=r[a]*c[a]*c[b];
						c[a]=c[b];
						stack[++j]=a;
					}
					else
					{
						error=1;
						break;
					}
				}
			}
			else;

			if(error) break;
		}
		if(error) printf("error\n");
		else
		{
			if(j==2)
			{
				a=stack[1];
				b=stack[2];

				if(c[a]==r[b])
				{
					sum+=r[a]*c[a]*c[b];
					c[a]=c[b];
					stack[++j]=a;
				}
				else
				{
					error=1;
					break;
				}
			}
			if(error) printf("error\n");
			else printf("%ld\n",sum);
		}
	}
}