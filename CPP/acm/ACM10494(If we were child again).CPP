#include<stdio.h>
#include<iostream.h>
#include<string.h>

#define MAX 3000

char s[MAX];
char a[MAX],ans[MAX];

void main()
{
	long i,j,r,q,n,l;
	char ch;

//	freopen("in.txt","r",stdin);

	while(gets(s))
	{
		sscanf(s,"%s %c %lld",a,&ch,&n);

		l=strlen(a);

		r=q=j=0;
		strcpy(ans,"0");

		for(i=0; i<l; i++)
		{
			r=(r*10)+a[i]-'0';
			if(r>=n)
			{
				q=r/n;
				r=r%n;
				ans[j++]=q+'0';
				ans[j]=0;
			}
			else 
			{
				if(strcmp(ans,"0")!=0)
				{	
					ans[j++]='0';
					ans[j]=0;
				}
			}
		}

		if(ch=='/') printf("%s\n",ans);
		else printf("%lld\n",r);
	}
}