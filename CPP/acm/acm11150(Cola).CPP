#include<stdio.h>

int find_max(int a,int b,int c)
{
	int large;

	if(a>b) large=a;
	else large=b;
	if(large>c)
		return large;
	else return c;
}

void main()
{
	long n,cola,res,new_,ans1,ans2,ans3,ans,input;

	while(scanf("%ld",&n)==1)
	{
		input=n;

		//no lending
		res=0;
		//if(n==2) res=1;
		cola=n;
		while(n>=3)
		{
			new_=n/3;
			res=n%3;

			cola+=new_;

			n=new_+res;
		}
		ans1=cola;

		//1 lending
		n=input+1;
		res=0;
		cola=input;
		while(n>=3)
		{
			new_=n/3;
			res=n%3;

			cola+=new_;

			n=new_+res;			
		}
		if(n>=1)
			ans2=cola;
		else ans2=-1;


		//2 lending
		n=input+2;
		res=0;
		cola=input;
		while(n>=3)
		{
			new_=n/3;
			res=n%3;

			cola+=new_;

			n=new_+res;			
		}
		if(n>=2)
			ans3=cola;
		else ans3=-1;

		ans=find_max(ans1,ans2,ans3);

		printf("%ld\n",ans);
	}
}