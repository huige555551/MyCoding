#include<stdio.h>

#define MAX 10002

int a[MAX];//input array
int b[MAX];//stores the last element of the LIS sequence of l length1 in b[l]
int length1;//it is the length1 of the Longest Increasing Subsequence
int total;//no of element in input array a[]

int L1[MAX];
int L2[MAX];

int binary_search1(int *x,int n,int key)
{
	int low,high,mid;

	low=1;
	high=n;

	while(low<=high)
	{
		mid=(low+high)/2;

		if(x[mid]==key)
			break;
		else if(key<x[mid])
			high=mid-1;
		else
			low=mid+1;
	}
	if(low>high) return low;
	return mid;
}

void LIS()
{
	int i;
	int pos;

	
	length1=1;
	b[1]=a[1];
	L1[1]=1;
	for(i=2; i<=total; i++)
	{
		if(a[i]>b[length1])
		{
			length1++;
			b[length1]=a[i];
			L1[i]=length1;
		}
		else if(a[i]<b[length1])
		{
			pos=binary_search1(b,length1,a[i]);
			b[pos]=a[i];
			L1[i]=pos;
		}
		else;
	}		
}

void reverse_LIS()
{
	int i;
	int pos;

	length1=1;
	b[1]=a[total];
	L2[total]=1;
	
	for(i=total-1; i>=1; i--)
	{
		if(a[i]>b[length1])
		{
			length1++;
			b[length1]=a[i];
			L2[i]=length1;
		}
		else if(a[i]<b[length1])
		{
			pos=binary_search1(b,length1,a[i]);
			b[pos]=a[i];
			L2[i]=pos;
		}
		else;
	}		
}

int min(int a,int b)
{
	if(a<b) return a;
	return b;
}

void wavio_seq()
{
	int i,n=0,max=0;

	for(i=1; i<=total; i++)
	{
		if(L1[i]==L2[i])
			n=L1[i]-1;
		else
			n=min(L1[i],L2[i])-1;

		if(n>max) max=n;
	}

	printf("%d\n",2*max+1);
}

void main()
{
	int i,n;

	freopen("in.txt","r",stdin);

	while(scanf("%d",&total)==1)
	{
		//clear
		for(i=1; i<=total; i++)
		{
			L1[i]=0;
			L2[i]=0;
			b[i]=0;
		}

		for(i=1; i<=total; i++)
		{
			scanf("%d",&n);
			a[i]=n;
		}

		LIS();
		reverse_LIS();

		wavio_seq();
	}
}