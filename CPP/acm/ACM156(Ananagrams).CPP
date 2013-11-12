#include<stdio.h>
#include<string.h>
#include<ctype.h>

char s[102];
char word[1002][102];
char a[1002][102];
int sum[1002];

int compare(char *s1,char *s2)
{
	int i,j;
	char t[100];

	if(strlen(s1)!=strlen(s2)) return 0;

	strcpy(t,s2);

	for(i=0; i<strlen(s1); i++)
	{
		for(j=0; j<strlen(t); j++)
		{
			if(toupper(s1[i])==toupper(t[j]))
			{
				t[j]='#';
				break;
			}
		}
		if(j==strlen(t)) return 0;
	}
	return 1;
}

void main()
{
	int i,j,t,n=0,m=0;

	freopen("in.txt","r",stdin);

	while(1)
	{
		scanf("%s",s);
		if(strcmp(s,"#")==0) break;
		strcpy(word[n++],s);
	}

	for(i=0; i<n; i++)
	{
		for(j=0; j<strlen(word[i]); j++)
		{
			t=toupper(word[i][j]);
			sum[i]+=t;
		}
	}

	for(i=0; i<n; i++)
	{
		if(sum[i]!=0 && strlen(word[i])!=1)
		{
			t=0;
			for(j=i+1; j<n; j++)
			{
				if(sum[i]==sum[j])
				{
					if(compare(word[i],word[j]))
					{
						sum[j]=0;
						t=1;
					}
				}
			}
			if(t) sum[i]=0;
		}
	}



	for(i=0; i<n; i++)
	{
		if(sum[i]!=0)
		{
			strcpy(a[m++],word[i]);
		}
	}

	for(i=0; i<m-1; i++)
	{
		for(j=m-1; j>i; j--)
		{
			if(strcmp(a[j-1],a[j])>0)
			{
				strcpy(s,a[j-1]);
				strcpy(a[j-1],a[j]);
				strcpy(a[j],s);
			}
		}
	}

	for(i=0; i<m; i++)
	{
		printf("%s\n",a[i]);
	}

}