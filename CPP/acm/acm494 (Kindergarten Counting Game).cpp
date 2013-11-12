#include<stdio.h>
#include<string.h>

#define MAX 500

void main()
{
	char str[MAX];
	int i,wordCount=1;

	while(gets(str)!=NULL)
	{
		wordCount = 0;
		for(i=0;str[i];i++)
		{
			if((str[i]>='A' && str[i]<='Z')||(str[i]>='a' && str[i]<='z'))
			{
				if(!((str[i+1]>='A' && str[i+1]<='Z')||(str[i+1]>='a' && str[i+1]<='z')))
					wordCount++;
			}
		}
		printf("%d\n",wordCount);
	}

}
