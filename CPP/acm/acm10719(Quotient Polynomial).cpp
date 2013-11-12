#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char s[200000];
long a[10002],ans[10002];
long n;

void get_num(char *p)
{
	char t[100];
	unsigned long first,i,j,k,l;

	l=strlen(p);
	first=1;
	for(i=0; i<l; i++)
	{
		if((p[i]>='0' && p[i]<='9')||(p[i]=='-'))
		{
			j=0;
			while((p[i]>='0' && p[i]<='9')||(p[i]=='-'))
			{
				t[j++]=p[i++];
			}
			t[j]=0;
			
			a[n++]=atoi(t);
		}
	}
}

void main()
{
	long i,k;

	//freopen("in.txt","r",stdin);

	while(gets(s))
	{
		k=atol(s);
		
		gets(s);
		n=0;
		get_num(s);

		ans[0]=a[0];
		for(i=1; i<n; i++)
		{
			ans[i]=a[i]+(k*ans[i-1]);
		}

		printf("q(x): ");
		for(i=0; i<n-1; i++)
		{
			printf("%ld ",ans[i]);
		}
		printf("\nr = %ld",ans[n-1]);
		printf("\n\n");

		//clearing all array
		for(i=0; i<n; i++)
		{
			ans[i]=a[i]=0;
		}
	}
}