#include<stdio.h>

void main()
{
	long long sum,n1,n2,n3,test,m;

	//freopen("in.txt","r",stdin);

	scanf("%lld",&test);

	while(test)
	{
		scanf("%lld",&m);

		sum=0;
		while(m)
		{
			scanf("%lld %lld %lld",&n1,&n2,&n3);
			sum+=(n1*n3);
			m--;
		}
		printf("%lld\n",sum);
		test--;
	}
}