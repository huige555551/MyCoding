#include<stdio.h>
#include<iostream.h>
#include<algorithm>
using namespace std;

#define MAX 10005

long a[MAX];

long binary_search(long key,long N)
{
	long low,mid,high,i;

	low=0;
	high=N-1;

	while(low<=high)
	{
		mid=(low+high)/2;

		if(a[mid]==key)
			break;
		else if(key<a[mid])
			high=mid-1;
		else 
			low=mid+1;
	}
	if(low>high) return -1;

	for(i=mid-1; i>=0; i--)
	{
		if(a[i]!=key) break;
	}

	return i+1;
}

void main()
{
	long N,Q,i,test=1,ans,p;
	
	//freopen("in.txt","r",stdin);

	while(cin>>N>>Q)
	{
		if(!N && !Q) break;

		for(i=0; i<N; i++)
		{
			cin>>a[i];
		}

		sort(a,a+N);
		
		printf("CASE# %ld:\n",test++);

		for(i=1; i<=Q; i++)
		{
			cin>>p;

			ans=binary_search(p,N);

			if(ans!=-1)
				printf("%ld found at %ld\n",p,ans+1);
			else printf("%ld not found\n",p);
		}
	}
}