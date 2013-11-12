#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

char word[100][20];
int num[100];
int factor[50][2];
long j;

void get_word(char *s)
{
	long i,l,k;
	l=strlen(s);

	for(i=0,j=0; i<l; i++)
	{
		if( (s[i]>='0'&&s[i]<='9') )
		{
			for(k=0; (s[i]>='0'&&s[i]<='9'); i++,k++)
			{
				word[j][k]=s[i];
			}
			word[j][k]=0;
			i--;
			num[j]=atoi(word[j]);
			j++;
		}
	}
}

int get_num()
{
	int i,n=1;

	for(i=0; i<j; i+=2)
	{
		n*=pow(num[i],num[i+1]);
	}

	return n;
}

void main()
{
	long i,k,n,t,count;
	char s[200];

	//freopen("in.txt","r",stdin);

	while(gets(s))
	{
		if(strcmp(s,"0")==0) break;
		get_word(s);

		n=get_num();
		n--;

		t=n;k=0;
		for(i=2; i<=sqrt(t); i++)
		{
			count=0;
			if(t%i==0)
			{
				while(t%i==0)
				{
					count++;
					t=t/i;
				}
				factor[k][0]=i;
				factor[k][1]=count;
				k++;
			}
		}

		if(t!=1)
		{
			factor[k][0]=t;
			factor[k][1]=1;
			k++;
		}

		for(i=k-1; i>=0; i--)
		{
			printf("%d %d ",factor[i][0],factor[i][1]);
		}
		printf("\n");
	}
}





















