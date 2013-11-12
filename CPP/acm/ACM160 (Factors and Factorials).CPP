#include<stdio.h>

int isprime(int n)
{
	int i;
	for(i=2; i<=n/2; i++)
	{
		if(n%i==0)return 0;
	}
	return 1;
}

void main()
{
	int prime[25]={0},p[100]={0};
	int i,j,k,n;

	for(i=2,j=0; i<98; i++)
	{
		if(isprime(i))prime[j++]=i;
	}

	while(1)
	{
		scanf("%d",&n);
		if(n==0)break;

		printf("%3d! =",n);

		for(i=n; i>1; i--)
		{
			for(k=i,j=0; k!=1; )
			{
				if(k%prime[j]==0)
				{
					k/=prime[j];
					p[j]++;
				}
				else
				{
					j++;
				}
			}
		}
		for(i=0; prime[i]<=n && i<25; i++)
		{
			if(i==15) printf("\n%9d",p[i]);
			else printf("%3d",p[i]);
			p[i]=0;
		}
		printf("\n");
	}

}
