#include<stdio.h>
#include<math.h>

#define MAX 100

void main()
{
	long long i,j,n1,n2,sum,s1[MAX],s2[MAX],s[MAX];

	while(scanf("%lld %lld",&n1,&n2)==2)
	{
		for(i=0; n1; i++)
		{
			s1[i]=n1%2;
			n1/=2;
		}

		for(j=0; n2; j++)
		{
			s2[j]=n2%2;
			n2/=2;
		}

		if(i>j)
		{
			while(j<i)
				s2[j++]=0;
		}
		else if(j>i)
		{
			while(i<j)
				s1[i++]=0;
		}

		for(i=0; i<j; i++)
		{
			s[i]=s1[i]^s2[i];
		}

		sum=0;
		for(i=0; i<j; i++)
		{
			sum+=s[i]*pow(2,i);
		}

		printf("%lld\n",sum);
	}

}