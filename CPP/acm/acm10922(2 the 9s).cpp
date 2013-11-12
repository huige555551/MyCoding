#include<stdio.h>
#include<string.h>

char s[1001];

int f(int n)
{
	int i=0;

	while(n)
	{
		i+=n%10;
		n=n/10;
	}

	return i;
}

void main()
{
	int deg,i,n;

	//freopen("in.txt","r",stdin);

	while(scanf("%s",s)==1)
	{
		if(strcmp(s,"0")==0) break;

		n=i=0;
		while(s[i])
		{
			n+=s[i]-'0';
			i++;
		}
		
		if(n%9==0)
		{
			deg=1;
			while(n!=9)
			{
				n=f(n);
				deg++;
			}
			printf("%s is a multiple of 9 and has 9-degree %d.\n",s,deg);
		}
		else printf("%s is not a multiple of 9.\n",s);
	}
}