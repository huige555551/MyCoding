#include<stdio.h>
#include<math.h>

#define MAX 1050

int prime[MAX];

void main()
{
	long i,j,k,n;
	char s[30];

	//freopen("in.txt","r",stdin);

	k=sqrt(MAX-1);

	prime[0]=1;
	prime[1]=0;
	for(i=2; i<=k; i++)
	{
		if(prime[i]==0)
		{
			for(j=i*i; j<=MAX-1; j+=i)
			{
				prime[j]=1;
			}
		}
	}

	while(scanf("%s",s)==1)
	{
		n=0;
		for(i=0; s[i]; i++)
		{
			if(s[i]>='a')
			{
				j=s[i]-96;
				n+=j;
			}
			else
			{
				j=s[i]-38;
				n+=j;
			}
		}

		if(prime[n]==0) printf("It is a prime word.\n");
		else printf("It is not a prime word.\n");
	}

}