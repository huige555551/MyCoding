#include<stdio.h>

void main()
{
	int s,d,i,j,n,p1,p2;

	scanf("%d",&n);

	while(n)
	{
		scanf("%d %d",&s,&d);
		if(s<d)
		{ 
			printf("impossible\n");
			n--;
			continue;
		}

		if(s%2==0)i=s/2;
		else i=s/2+1;

		j=d/2;

		p1=i+j;
		p2=s-p1;

		if(p1-p2==d) printf("%d %d\n",p1,p2);
		else printf("impossible\n");
		n--;
	}
}