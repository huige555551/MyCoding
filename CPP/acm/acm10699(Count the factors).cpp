#include<stdio.h>
#include<math.h>

void main()
{
	long n,i,num,count,l;

	freopen("in.txt","r",stdin);

	while(scanf("%ld",&n)==1)
	{
		if(n==0) break;
		
		count=0;
		l=(long)sqrt(n);
		for(num=n,i=2; i<=l; i++)
		{
			if(num%i==0)
			{
				while(num%i==0)
				{
					num=num/i;
				}
				count++;
			}
			l=(long)sqrt(num);
		}
		if(num!=0) count++;

		printf("%ld : %ld\n",n,count);
	}
}