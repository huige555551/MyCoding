#include<stdio.h>
#include<string.h>

#define MAX 1000001

char s[MAX];
long a[MAX];

void main()
{
	long i,l,n,n1,n2,Case=1;

	freopen("in.txt","r",stdin);

	while(scanf("%s",s)==1)
	{
		if(strcmp(s,"")==0) break;

		if(Case!=1)
		{
			//memset(a,0,sizeof(a));
			for(i=0; i<l; i++)
			{
				a[i]=0;
			}
		}

		l=strlen(s);
		for(i=1; i<l; i++)
		{
			if(s[i]!=s[i-1])
			{
				a[i]=a[i-1]+1;
			}
			else
			{
				a[i]=a[i-1];
			}
		}

		printf("Case %ld:\n",Case++);

		scanf("%ld",&n);
		for(i=0; i<n; i++)
		{
			scanf("%ld %ld",&n1,&n2);

			if(a[n1]==a[n2]) printf("Yes\n");
			else printf("No\n");
		}
	}
}