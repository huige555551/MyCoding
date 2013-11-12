#include<stdio.h>
#include<string.h>

void make_bin13(int x)
{
	int c,v=0x1000;  /*v=4096 (in decimal=(0001000000000000)binary)*/

	for(c=0;c<13;c++)
	{
		if(x&v)
			putchar('1');
		else
			putchar('0');
		v>>=1;
	}
}

/*
void make_bin13(int num)
{
	int i=0;
	char s[20]={0};

	while(num)
	{
		if(num%2) s[i]='1';
		else s[i]='0';
		i++;
		num=num/2;
	}

	for(i=1; i<=13-strlen(s); i++)
	{
		printf("0");
	}
	for(i=strlen(s)-1; i>=0; i--)
	{
		printf("%c",s[i]);
	}
}
*/
void main()
{
	int testcase,num1,num2;
	char op;

	/*freopen("446.in","r",stdin);*/

	scanf("%d",&testcase);

	while(testcase)
	{
		scanf("%X %c %X",&num1,&op,&num2);

		make_bin13(num1);
		printf(" %c ",op);
		make_bin13(num2);

		if(op=='+')
			printf(" = %d",num1+num2);
		else if(op=='-')
			printf(" = %d",num1-num2);

		printf("\n");

		testcase--;
	}
}