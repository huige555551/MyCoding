#include<stdio.h>

typedef long big;

big d[10],min[10];

big get_digit(big n,big pos,big len)
{
	big i,p,t;

	p=len-pos;
	i=-1;

	while(n)
	{
		i++;
		t=n%10;
		n=n/10;
		if(i==p) break;
	}

	return t;
}

void main()
{
	big n,num,rank,digit,ans,i,pos;

	//freopen("in.txt","r",stdin);

	d[1]=9;
	d[2]=189;
	d[3]=2889;
	d[4]=38889;
	d[5]=488889;
	d[6]=5888889;
	d[7]=68888889;
	d[8]=788888889;
	d[9]=2000000000;

	min[1]=1;
	min[2]=10;
	min[3]=100;
	min[4]=1000;
	min[5]=10000;
	min[6]=100000;
	min[7]=1000000;
	min[8]=10000000;
	min[9]=100000000;

	while(scanf("%lld",&n)==1)
	{
		for(i=1; i<=8; i++)
		{
			if(d[i]>=n) break;
		}	

		digit=i;

		rank=n-d[digit-1];

		num=rank/digit;
		if(rank%digit==0) num--;
		num=num+min[digit];
		pos=rank%digit;
		if(pos==0) pos=digit;

		ans=get_digit(num,pos,digit);

		printf("%lld\n",ans);
	}
}