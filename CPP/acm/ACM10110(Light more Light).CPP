#include<stdio.h>
#include<math.h>

void main()
{
	long long n;
	double doublevalue;

	//freopen("in.txt","r",stdin);

	while(scanf("%lld",&n)==1)
	{
		if(n==0) break;

		doublevalue=sqrt(n);
		
		//if i use only 0 get wrong answer so must use 0.00
		if(floor(doublevalue)-doublevalue==0.00) printf("yes\n");
		else printf("no\n");
	}
}

//>>every positive integer n is divisible 
//by an even number of distinct integers(including 1 and n), 

//>>only square integers are divisible 
//by an odd number of distinct integers(including 1 and that number)
