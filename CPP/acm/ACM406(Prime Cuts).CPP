#include<stdio.h>
/*if i use 1000 then it gives WA but after using 10000 i get AC..STRANGE*/
#define MAX 10000

void main()
{
	int prime[MAX],i,j,num,is_prime,n,c,count,mid;
	/*store prime numbers in int array*/
	prime[0]=1;
	prime[1]=2;
	for(i=2,num=3; num<=MAX; num++)
	{
		is_prime=1;
		for(j=2; j<=num/2; j++)
		{
			if((num%j)==0)
			{
				is_prime=0;
				break;
			}
		}
		if(is_prime)
			prime[i++]=num;
	}
	/*take input*/
	while(scanf("%d %d",&n,&c)==2)
	{
		printf("%d %d:",n,c);
		/*count the no of primes between 1 and n*/
		for(count=0; prime[count]<=n; count++);
		/*if count even*/
		if(count%2==0)
		{    /*if no of primes is not less than required*/
			if(count>=(c*2))
			{    /*index of mid primes*/
				mid=count/2;
				/*start print primes from idex i=(mid-c)&& do it upto required*/
				for(i=mid-c,j=1; j<=c*2; i++,j++)
				{
					printf(" %d",prime[i]);
				}
			}
			else
			{
				for(i=0; i<count; i++)
				{
					printf(" %d",prime[i]);
				}
			}
		}
		/*if count odd*/
		else
		{    /*if no of primes is not less than required*/
			if(count>=((c*2)-1))
			{
				mid=count/2;
				for(i=mid-(c-1),j=1; j<=(c*2)-1; i++,j++)
				{
					printf(" %d",prime[i]);
				}
			}
			else
			{
				for(i=0; i<count; i++)
				{
					printf(" %d",prime[i]);
				}
			}
		}
		printf("\n\n");
	}
}