#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<algorithm>
using namespace std;

int a[52],t[52];

void main()
{
	char s[200];
	int i,j,max,k;

	//freopen("in.txt","r",stdin);

	while(gets(s))
	{
		memset(a,0,sizeof(a));

		max=-1;
		for(i=0; s[i]; i++)
		{
			if(isalpha(s[i]))
			{
				if(islower(s[i]))
				{
					j=s[i]-'a'+26;
				}
				else
				{
					j=s[i]-'A';
				}
				a[j]++;

				if(max<a[j])
				{
					max=a[j];
					k=0;
					t[k]=j;
					k++;
				}
				else if(max==a[j])
				{
					t[k]=j;
					k++;
				}
			}
		}
		
		sort(t,t+k);

		for(i=0; i<k; i++)
		{
			printf("%c",t[i]<26 ? t[i]+'A':t[i]+71);
		}
		printf(" %d\n",max);
	}
}