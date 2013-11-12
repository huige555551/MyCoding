#include<stdio.h>
#include<math.h>

#define REMAX 100000000
#define MAX REMAX/16+1

char chkbit[MAX];

#define get(x) ((chkbit[x>>3]>>(x&7))&1)
/*
int get(int x)
{
	int i;
	i=((chkbit[x>>3]>>(x&7))&1);
	return i;
}
*/
long isprime(long x)
{
	long i;
	i=get(x/2);

	if(i==0) return 1;
	return 0;
}

void generate_sieve()
{
	long i,j,k,t;

	k=(long)sqrt(REMAX);

	for(i=3; i<=k; i+=2)
	{
		if(get(i/2)==0)
		{
			for(j=i*i; j<REMAX; j+=2*i)
			{
				if(j%2)
				{
					t=j/2;
					chkbit[t>>3]|=1<<(t&7);//prime na hole bit 0 kore rakha hosse
				}
			}
		}
	}

	for(i=3; i<=100; i+=2)
	{
		if(get(i/2)==0)printf("%ld\n",i);
	}
}

void main()
{
	long num,mid,found;

	generate_sieve();

	while(scanf("%ld",&num)==1)
	{
		if(num<3)
			printf("%ld is not the sum of two primes!\n",num);
		else if(num%2)
		{
			if(isprime(num-2))
			{
				if(num-2>2)
					printf("%ld is the sum of 2 and %ld.\n",num,num-2);
				else
					printf("%ld is not the sum of two primes!\n",num);
			}
			else
				printf("%ld is not the sum of two primes!\n",num);
		}
		else
		{
			found=0;
			mid=num/2;
			if(mid!=2 && mid%2==0) mid--;

			for(mid; mid>1; mid=mid-2)
			{
				if(mid!=num-mid)
				{
					if(isprime(mid) && isprime(num-mid))
					{
						printf("%ld is the sum of %ld and %ld.\n",num,mid,num-mid);
						found=1;
						break;
					}
				}
			}
			if(!found)
				printf("%ld is not the sum of two primes!\n",num);
		}
	}

}

/*
Setting k-th bit of x: x |= 1 << k;
Clearing k-th bit: x &= ~(1 << k);
Getting k-th bit: return (x >> k) & 1;
Flipping k-th bit: x ^= 1 << k; (replaces 0 by 1, and 1 by 0.)
(Here, least significant bit is bit #0.)



 you can alse speed it up with this code:
Code:

for(num=5,f=2;num<REMAX;num+=f,f=6-f)

You should handle 3 separatly. It is faster than yours by 33%.

   a/8 into a>>3 and a%8 into a&7


*/

