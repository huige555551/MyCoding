#include<stdio.h>
#include<string.h>

void main()
{
	int N,i,count,right,m,a[101];

	while(scanf("%d",&N)==1)
	{
		if(N==0)break;
		else if(N==13) printf("1");
		else
		{
			for(m=5; ; m++)
			{
				memset(a,0,sizeof(a));

				i=1;
				a[i]=1;
				while(1)
				{
					i++;
					count=0;
					while(count!=m)
					{
						if(a[i]==0)count++;
						if(count!=m)
						{
							i=(i+1)%N;
							if(i==0)i=N;
						}
					}
					a[i]=1;
					if(i==N)i=0;
					if(i==13)break;
				}
				right=1;
				for(i=1; i<=N; i++)
				{
					if(a[i]==0)
					{
						right=0;
						break;
					}
				}
				if(right)
				{
					printf("%d",m);
					break;
				}
			}
		}
		printf("\n");
	}
}