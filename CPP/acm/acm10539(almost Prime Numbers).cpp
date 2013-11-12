#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

#define MAX 1000001
typedef long long big;

int prime[MAX];
big a[80080];

void main()
{
	big i,j,k,test,n,b,c,t,count;

	//freopen("in.txt","r",stdin);
	
	prime[0]=prime[1]=1;
	k=(big)sqrt(MAX-1);
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

	n=0;
	for(i=2; i<=1e6; i++)
	{
		if(prime[i]==0)
		{
			for(j=i*i; j<=1e12; j*=i)
			{
				a[n]=j;
				n++;
			}
		}
	}

	//sort(a,a+n);

	scanf("%lld",&test);
	
	while(test)
	{
		scanf("%lld %lld",&b,&c);
		
		count=0;
		for(i=0; i<n && a[i]<=c; i++)
		{
			if(a[i]>=b && a[i]<=c)
			{
				count++;
			}
		}

		printf("%lld\n",count);

		test--;
	}

}

/*
There are many problems:
i have to use long long.
gcc te cin die input nite hobe.
i cannot use %lld for long in gcc in printf();
for better result:
 i have to use binary search
 qsort() will make faster 
 
   
	 for qsort():
	

int cmp1(const void *a, const void *b) 
{ 
   long long *aa, *bb; 
   aa = (long long *)a; 
   bb = (long long *)b; 
   if(*aa > *bb) 
      return 1; 
   else if(*aa == *bb) 
      return 0; 
   else 
      return -1; 
}

qsort(a, n, sizeof(long long), cmp1); 

*/