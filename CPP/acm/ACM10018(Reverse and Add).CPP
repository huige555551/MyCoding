#include<stdio.h>
#include<math.h>

unsigned long rev_num(unsigned long n)
{
	int i,length;
	unsigned long temp,r_n=0;

	temp=n;

	for(length=0; temp; length++)
	{
		temp=temp/10;
	}

	for(length; n; length--)
	{
		r_n+=(n%10)*pow(10,length-1);
		n=n/10;
	}

	return r_n;
}

void main()
{
	unsigned long n1,n2;
	int count,t;

	scanf("%d",&count);

	while(count)
	{
		scanf("%lu",&n1);

		t=0;
		while(1)
		{
			n2=rev_num(n1);

			if(n1-n2==0)
				break;

			n1=n1+n2;

			t++;
		}

		printf("%d %lu\n",t,n1);

		count--;
	}
}