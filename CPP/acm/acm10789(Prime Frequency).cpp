#include<stdio.h>
#include<math.h>

int a[10],b[26],c[26],prime[2002];
char s[2002];

void main()
{
	int testcase,i,j,k,n,empty;

	//freopen("in.txt","r",stdin);

	prime[0]=prime[1]=1;
	k=sqrt(2002);
	for(i=2; i<=k; i++)
	{
		if(prime[i]==0)
		{
			for(j=i*i; j<2002; j+=i)
			{
				prime[j]=1;
			}
		}
	}

	scanf("%d",&testcase);

	n=1;
	while(n<=testcase)
	{
		scanf("%s",s);

		for(i=0; s[i]; i++)
		{
			if(s[i]>='0' && s[i]<='9')
			{
				a[s[i]-'0']++;
			}
			else if(s[i]>='A' && s[i]<='Z')
			{
				b[s[i]-'A']++;
			}
			else
			{
				c[s[i]-'a']++;
			}
		}

		printf("Case %d: ",n);

		empty=1;
		for(i=0; i<10; i++)
		{
			if(prime[a[i]]==0)
			{
				printf("%d",i);
				empty=0;
			}
			a[i]=0;
		}
		for(i=0; i<26; i++)
		{
			if(prime[b[i]]==0)
			{
				printf("%c",i+'A');
				empty=0;
			}
			b[i]=0;
		}
		for(i=0; i<26; i++)
		{
			if(prime[c[i]]==0)
			{
				printf("%c",i+'a');
				empty=0;
			}
			c[i]=0;
		}
		if(empty) printf("empty");

		printf("\n");

		n++;
	}
}