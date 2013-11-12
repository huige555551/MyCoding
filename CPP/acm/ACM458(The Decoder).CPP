#include<stdio.h>

void main()
{
	char c;

	while ((c = getchar()) != EOF)
		if(c=='\n')printf("%c",c);
		else printf("%c",c-7);
}