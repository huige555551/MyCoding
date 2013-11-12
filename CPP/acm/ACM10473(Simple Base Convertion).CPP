#include <stdio.h>
#include <stdlib.h>

void main()
{
	char line[50];
	char *lixo;
	long i;

	//freopen("in.txt","r",stdin);

	while(scanf("%s",line)==1)
	{
		i=atol(line);

		if(i<0) break;

		else if (line[0] == '0' && line[1] == 'x')
		{
			i = strtol(line, &lixo, 16);

			printf("%ld\n", i);
		}
		else printf("0x%X\n",i);
	}
}
