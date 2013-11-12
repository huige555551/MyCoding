#include<stdio.h>

void main()
{
	long long n1,n2;
	long long carry,count,i,p1,p2,sum;

	while(1)
	{
		scanf("%lld %lld",&n1,&n2);

		if(n1==0&&n2==0)
			break;

		carry=0;
		count=0;

		for(i=0; n1!=0 || n2!=0; i++)
		{
			p1=n1%10;
			p2=n2%10;

			n1=n1/10;
			n2=n2/10;

			sum=p1+p2+carry;

			if(sum>=10)
			{
				count++;
				carry=1;
			}
			else
				carry=0;
		}

		if(count==0)
			printf("No carry operation.\n");
		else if(count==1)
			printf("1 carry operation.\n");
		else
			printf("%lld carry operations.\n",count);
	}
}