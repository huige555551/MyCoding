#include<stdio.h>
#include<math.h>

#define MAX 20

int b[MAX];
//int a[MAX];
//int c[MAX];
//int ncandidate;
int finished;

int is_prime(int x)
{
	int i;

	if(x!=2 && x%2==0) return 0;

	for(i=3; i<=sqrt(x); i+=2)
	{
		if(x%i==0) return 0;
	}

	return 1;
}

int is_a_solution(int k,int n)
{
	if(k==n) return 1;
	return 0;
}

void construct_solution(int a[],int c[],int k,int n,int *ncandidate)
{
	int i,sum=0;
	*ncandidate=0;

	for(i=1; i<=n; i++)
		b[i]=0;
	for(i=1; i<k; i++)
	{
		b[a[i]]=1;
	}

	for(i=1; i<=n; i++)
	{
		if(b[i]==0)
		{
			if(is_prime(a[k-1]+i))
			{
				*ncandidate+=1;
				int j=*ncandidate;
				c[*ncandidate]=i;
			}
		}
	}
}

void process_solution(int a[],int k,int n)
{
	int i;

	if(is_prime(a[n]+a[1]))
	{
		for(i=1; i<=n; i++)
		{
			if(i!=1) printf(" ");
			printf("%d",a[i]);
		}
		printf("\n");
	}
}

void backtrack(int a[],int k,int n)
{
	int i,ncandidate;
	int c[MAX];
	a[1]=1;

	if(is_a_solution(k,n))
	{
		process_solution(a,k,n);
	}
	else
	{
		k=k+1;
		construct_solution(a,c,k,n,&ncandidate);

		for(i=1; i<=ncandidate; i++)
		{
			a[k]=c[i];
			backtrack(a,k,n);
			//if(finished) return;
		}
	}
}

void main()
{
	int a[MAX]={0};
	int test=1,n;

	while(scanf("%d",&n)==1)
	{
		if(test!=1) printf("\n");
		printf("Case %d:\n",test++);
		backtrack(a,1,n);
	}
}