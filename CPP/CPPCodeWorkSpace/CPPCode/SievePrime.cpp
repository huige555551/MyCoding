#include<stdio.h>
#include<math.h>

//#define REMAX 100000000
#define REMAX 100
#define MAX REMAX/8+1

char chkbit[MAX];

//#define get(x) ((chkbit[x>>3]>>(x&7))&1)

int get(int x)
{
	int i;
	int n = x>>3; //x/8
	int m = x&7;  //x%8

	int p = (chkbit[n]>>m)&1;

	return p;

	//i=((chkbit[x>>3]>>(x&7))&1);
	//return i;
}


void generate_sieve()
{
	long i,j,k,t;

	k=(long)sqrt((double)REMAX);

	for(i=3; i<=k; i+=2)
	{
		if(get(i)==0)
		{
			for(j=i*i; j<REMAX; j+=2*i)
			{
				if(j%2)
				{
					//t=j/2;
					chkbit[j>>3]|=1<<(j&7);//prime na hole bit 1 kore rakha hosse
				}
			}
		}
	}

	for(i=3; i<=100; i+=2)
	{
		if(get(i)==0)printf("%ld\n",i);
	}
}

void main()
{

	generate_sieve();	

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

   a/8 into a>>3 and 
   a%8 into a&7


*/

