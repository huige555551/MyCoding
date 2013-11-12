#include<stdio.h>

void main()
{
	char s[100];
	int top,north,west,t,n,i;

	freopen("in.txt","r",stdin);

	while(scanf("%d",&n)==1)
	{
		if(n==0) break;

		top=1;
		north=2;
		west=3;

		for(i=1; i<=n; i++)
		{
			scanf("%s",s);

			if(s[0]=='n')
			{
				t=top;
				top=7-north;
				north=t;
			}
			else if(s[0]=='s')
			{
				t=top;
				top=north;
				north=7-t;
			}
			else if(s[0]=='e')
			{
				t=top;
				top=west;
				west=7-t;
			}
			else//s[0]=='w'
			{
				t=top;
				top=7-west;
				west=t;
			}
		}

		printf("%d\n",top);
	}
}