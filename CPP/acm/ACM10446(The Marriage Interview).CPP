#include<stdio.h>

//typedef unsigned __int64 datatype;
typedef unsigned long long datatype;
datatype a[62][62];

void trib()
{
	int i,j,k;
	datatype sum;

	for(i=0; i<61; i++) a[0][i]=1;
	for(i=0; i<61; i++) a[1][i]=1;

	for(i=2;i<61;i++)
	{
		for(j=0; j<61; j++)
		{
			sum=0;
			for(k=0; k<=j; k++)
			{
				if(i-k<0) sum++;
				else sum+=a[i-k][j];
			}
			a[i][j]=sum+1;
		}
	}
}



void main()
{
	int n,back,test=1;

	trib();

	while(scanf("%d %d",&n,&back)==2)
	 //while(scanf("%I64u %I64u",&n,&back)==2)
	{
		if(n>60) break;

		printf("Case %d: ",test++);
		//printf("Case %I64u: ",test++);

		if(n<0 || back<0)
			printf("1\n");
		else
			printf("%llu\n",a[n][back]);
			//printf("%I64u\n",a[n][back]);
	}
}