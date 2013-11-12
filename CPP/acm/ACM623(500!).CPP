#include<stdio.h>
#include<string.h>

#define MAX 1002
#define S 3000

char a[MAX][S];
char num[MAX][100];
int count;

void str_rev(char *p)
{
	char r[S]={0};
	int i,j;

	for(i=strlen(p)-1,j=0; i>=0; j++,i--)
	{
		r[j]=p[i];
	}

	for(i=0; r[i]; i++)
	{
		p[i]=r[i];
	}
}


void itoa(int n)
{
	int l,i,temp;

	temp=n;

	l=0;
	while(temp)
	{
		temp=temp/10;
		l++;
	}

	for(i=l-1; n; i--)
	{
		num[count][i]=(n%10)+'0';
		n=n/10;
	}
}


void multi(char *s1,char *s2)
{
	int i,j,l1,l2,num1,num2;
	char ans[S]={0};

	str_rev(s1);
	str_rev(s2);

	l1=strlen(s1);
	l2=strlen(s2);

	for(i=0; i<l2; i++)
	{
		num2=s2[i]-'0';

		for(j=0; j<l1; j++)
		{
			num1=s1[j]-'0';

			ans[i+j]+=num1*num2;

			if(ans[i+j]>9)
			{
				ans[i+j+1]+=ans[i+j]/10;
				ans[i+j]%=10;
			}
		}
	}

	for(i=0; i<(l1+l2); i++)
	{
		ans[i]+='0';
	}
	ans[i]=0;

	str_rev(ans);
	str_rev(s2);

	while(ans[0]=='0')
	{
		for(i=0; i<(l1+l2); i++)
		{
			ans[i]=ans[i+1];    /* setting number  in actual order */
		}
	}

	strcpy(a[count],ans);
}


void main()
{
	int i,n;

	strcpy(num[0],"0");
	for(count=1; count<=1000; count++)
	{
		itoa(count);
	}

	strcpy(a[0],"1");
	for(count=1; count<=1000; count++)
	{
		strcpy(a[count],num[count]);
		multi(a[count],a[count-1]);
	}


	while(scanf("%d",&n)!=EOF)
	{
		printf("%d!\n",n);

		printf(a[n]);

		printf("\n");
	}
}