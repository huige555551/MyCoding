#include<stdio.h>
#include<string.h>

#define MAX_LEN(a,b) a>b?a:b

#define MAX 10000

char array[100];

void main()
{
	char s[MAX][25];
	int str_num=0,max_len=0,match;
	int i,j,k;

	while( gets( s[str_num] )!=NULL )
	{
		if(s[str_num][0]=='#') break;

		max_len=MAX_LEN( max_len, strlen(s[str_num]) );

		str_num++;
	}

	for(j=0; j<max_len; j++)
	{
		for(i=0; i<str_num; i++)
		{
			if(! (j>=strlen(s[i])) )
			{
				/*if array has no element*/
				if(!strlen(array))
					array[0]=s[i][j];

				else
				{
					match=0;

					for(k=0; k<strlen(array); k++)
					{
						if(s[i][j]==array[k])
						{
							match=1;
							break;
						}
					}
					/*if the element not in the array*/
					if(!match)
					{
						array[k]=s[i][j];
						array[k+1]=0;
					}
				}
			}
		}
	}

	printf("%s\n",array);
}