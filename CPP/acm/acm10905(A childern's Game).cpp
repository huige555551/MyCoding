#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char s[100][100];

void main()
{
	int i,j,n;
	char s1[100],s2[100],t[100];

	//freopen("in.txt","r",stdin);

	while(scanf("%d",&n)==1)
	{
		if(n==0) break;

		for(i=0; i<n; i++)
		{
			scanf("%s",s[i]);
		}

		for(i=0; i<n; i++)
		{
			for(j=i+1; j<n; j++)
			{
				strcpy(s1,s[i]);
				strcpy(s2,s[j]);

				strcat(s1,s[j]);
				strcat(s2,s[i]);

				if(strcmp(s1,s2)<0)
				{
					strcpy(t,s[i]);
					strcpy(s[i],s[j]);
					strcpy(s[j],t);
				}
			}
		}

		for(i=0; i<n; i++)
		{
			printf("%s",s[i]);
		}

		printf("\n");
	}
}