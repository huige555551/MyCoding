#include<stdio.h>

void main()
{
	int t,n,m;

	while(scanf("%d %d",&n,&m)==2)
	{
		m--;
		 
		t=(n-1)+(n*m);

		printf("%d\n",t);
	}
}