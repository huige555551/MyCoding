#include<stdio.h>
/*it must be declare here.or i cannot get AC.BE CAREFUL*/
long long n[1000000],p[1000000];

void main()
{
	long long i,j,k,c,m,count,check;

	i=0;
	while(scanf("%lld",&n[i++])!=EOF);

	m=0;
	for(j=0; j<=i-2; j++)
	{
		count=1;
		check=1;
		/*check if it occurs before or not*/
		if(j!=0)
		{
			for(c=m-1; c>=0; c--)
			{
				if(n[j]==p[c])
				{
					check=0;
					break;
				}
			}
		}
		/*if it is new then count the occurance*/
		if(check)
		{
			for(k=j+1; k<=i-2; k++)
			{
				if(n[j]==n[k])
					count++;
			}
			p[m++]=n[j];

			printf("%lld %lld\n",n[j],count);
		}
	}
}