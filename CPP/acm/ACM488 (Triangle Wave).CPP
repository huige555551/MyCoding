#include<stdio.h>
#include<stdlib.h>

void main()
{
	int c,count,f,w,i,j,k,l,m;
	char ch[100];

	gets(ch);
	count=atoi(ch);


	for(c=0; c<count; c++)
	{
		printf("\n");
		scanf("%d %d",&f,&w);
		for(i=0; i<w; i++)
		{
			for(j=1; j<=f; j++)
			{
				for(k=1; k<=j; k++)
				{
					printf("%d",j);
					if(k==j&&j==f)
					{
						printf("\n");
						for(l=k-1; l>0; l--)
						{
							for(m=1; m<=l; m++)
							{
								printf("%d",l);
							}
							printf("\n");
						}
					}
				}
				if(i==w-1&&j==f&&l==0&&m==2)break;
				else printf("\n");
			}
		}
	}

}