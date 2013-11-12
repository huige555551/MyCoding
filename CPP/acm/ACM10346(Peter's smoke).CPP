#include <stdio.h>

void main()
{
	long n,k,smoke,smoke_tmp,butt,butt_extra;

	while(scanf("%ld%ld",&n,&k)==2)
	{
		smoke=n;
		butt_extra=0;
		butt=smoke;

		while(butt>=k)
		{
			smoke_tmp=butt/k;
			butt_extra=butt%k;

			smoke+=smoke_tmp;
			butt=smoke_tmp+butt_extra;
		}

		/*smoke=n+(n-1)/(k-1);*/
		printf("%ld\n",smoke);
	}
}
