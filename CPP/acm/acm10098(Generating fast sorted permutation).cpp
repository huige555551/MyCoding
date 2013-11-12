#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

using namespace std;

char s[100];

void main()
{
	int n,i,j,first=1;
	char t;

	scanf("%d",&n);

	while(n)
	{
		if(!first)printf("\n");
		first=0;

		scanf("%s",s);

		for(i=1; i<strlen(s); i++)
		{
			for(j=strlen(s)-1; j>=i; j--)
			{
				if(s[j-1]>s[j])
				{
					t=s[j];
					s[j]=s[j-1];
					s[j-1]=t;
				}
			}
		}
		
		printf("%s\n",s);
		while(1)
		{
			if(next_permutation(s,s+strlen(s)))
				printf("%s\n",s);
			else break;
		}
		n--;
	}
}