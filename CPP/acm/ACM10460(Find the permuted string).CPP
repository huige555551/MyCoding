#include<stdio.h>
#include<math.h>
#include<string.h>

long double fact[27];
char s[100];
int serial;

void factorial()
{
	int i;
	fact[0]=1;

	for(i=1; i<=26; i++)
	{
		fact[i]=i*fact[i-1];
	}
}

void find_perm()
{
	long double unit,p;
	int length,i,position,j;
	char t[30];

	length=strlen(s);
	t[0]=s[0];

	for(i=2; i<=length; i++)
	{
		unit=fact[length]/fact[i];
		p=ceil(serial/unit);
		position=(int)(p-floor(p/(long double)i)*(long double)i);

		if(position==0) position=i;

		for(j=i-1; j>=position-1; j--)
		{
			t[j+1]=t[j];
		}
		t[position-1]=s[i-1];
	}
	t[length]=0;

	printf("%s\n",t);
}

void main()
{
	int test;

	//freopen("in.txt","r",stdin);

	factorial();

	scanf("%d",&test);

	while(test)
	{
		scanf("%s",s);
		scanf("%d",&serial);
		find_perm();
		test--;
	}
}