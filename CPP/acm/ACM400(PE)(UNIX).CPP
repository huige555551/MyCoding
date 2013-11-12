#include<stdio.h>
#include<string.h>

void main()
{
	int i,j,k,n,max,column,row,compare;
	char file[100][80],temp[80],a[20];

	freopen("input.txt", "r", stdin);

	while(scanf("%d",&n)!=EOF)
	{
		max=0;
		for(i=0; i<n; i++)
		{
			scanf("%s",file[i]);

			if(max<strlen(file[i]))
				max=strlen(file[i]);
		}

		for(j=0; j<n-1; j++)
		{
			for(k=j+1; k<n; k++)
			{
				compare=strcmp(file[k],file[j]);

				if(compare<1)
				{
					strcpy(temp , file[k]);
					strcpy(file[k] , file[j]);
					strcpy(file[j] , temp);
				}
			}
		}

		column=60/(max+2);

		/*row num*/
		if(column==0)
			row=n;
		else if(n/column==0)
			row=1;

		else if(n%column==0)
			row=n/column;

		else
			row=(n/column)+1;


		for(i=1; i<=60; i++)
			printf("-");
		printf("\n");

		for(i=0; i<row; i++)
		{
			for(j=0; (i+j)<n; j+=row)
			{
				printf("%s",file[i+j]);

				if(i+j+row<n)
				{
					for(k=1; k<=max+2-strlen(file[i+j]); k++)
					{
						printf(" ");
					}
				}
				else
				{
					for(k=1; k<=max-strlen(file[i+j]); k++)
					{
						printf(" ");
					}
				}
			}
			printf("\n");
		}
	}
}