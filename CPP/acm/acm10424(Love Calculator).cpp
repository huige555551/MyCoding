#include<stdio.h>

#define MAX 100

int calc(char *s);

void main()
{
	char s1[MAX],s2[MAX];
	int n1,n2;
	double result;

	while(gets(s1)!=NULL)
	{
		gets(s2);

		n1=calc(s1);
		n2=calc(s2);

		if(n1>n2)
			result=((double)n2/n1)*100;
		else if(n1<n2)
			result=((double)n1/n2)*100;
		else
			result=100.00;

		printf("%.2lf %\n",result);
	}

}

int calc(char *s)
{
	int i,sum,temp;

	sum=0;
	for(i=0; s[i]; i++)
	{
		if(s[i]>='a' && s[i]<='z')
			sum+=s[i]-96;
		else if(s[i]>='A' && s[i]<='Z')
			sum+=s[i]-64;
	}

	while(sum>=10)
	{
		temp=0;
		while(sum)
		{
			temp+=sum%10;
			sum/=10;
		}
		sum=temp;
	}

	return sum;
}