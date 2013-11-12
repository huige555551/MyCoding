#include<stdio.h>

void main()
{
	char c;
	int count=0;

	while((c=getchar())!=EOF )
	{
		if(c=='"')
		{
			count++;

			if(count%2)
			{
				printf("``");
			}
			else
			{
				printf("''");
			}
		}
		else
			putchar(c);
	}
}