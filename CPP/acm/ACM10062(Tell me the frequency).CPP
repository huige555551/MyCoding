#include<stdio.h>
#include<string.h>

char s[1000];
int a[200],b[200],c[200];

void main()
{
	int i,j,k,max,first=0;

	//freopen("in.txt","r",stdin);

	while(gets(s)!=NULL)
	{

		if(first!=0)printf("\n");
		first=1;

		memset(a,0,sizeof(a));

		for(i=0; i<strlen(s); i++)
		{
			j=s[i];
			a[j]++;
		}

		k=0;

		for(i=127; i>=32; i--)
		{
			max=127;
			for(j=126; j>=32; j--)
			{
				if(a[max]<=a[j])
				{
					max=j;
					c[k]=a[max];
				}
			}
			if(c[k]==0)break;
			b[k++]=max;
			a[max]=0;
		}


		for(i=k-1; i>=0; i--)
		{
			printf("%d %d\n",b[i],c[i]);
		}
	}

}