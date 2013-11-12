#include<stdio.h>
#include<string.h>

#define MAX 1002

char X[MAX],Y[MAX];
int i,j,k,m,n,c[MAX],a[MAX];

int LCSlength() 
{
	m=strlen(X);
	n=strlen(Y);

	//for (i=1;i<=m;i++) c[i][0]=0;
	//for (j=0;j<=n;j++) c[0][j]=0;
	for(i=0; i<=n; i++) a[i]=0;
	for(j=0; j<=n; j++) c[j]=0;

	for (i=1;i<=m;i++)
	{
		for (j=1;j<=n;j++) 
		{ 
			if (X[i-1]==Y[j-1]) 
			{
				//c[i][j]=c[i-1][j-1]+1;       
				c[j]=a[j-1]+1;
			}
			else if (a[j]>=c[j-1]) 
			{
				//c[i][j]=c[i-1][j];        
				c[j]=a[j];
			}
			else 
			{
				//c[i][j]=c[i][j-1];       
				c[j]=c[j-1];
			} 
		}
		for(k=1; k<=n; k++){ a[k]=c[k]; }
	}

	return c[n];
}

void main()
{
	//freopen("in.txt","r",stdin);

	while( gets(X) && gets(Y) )
	{
		printf("%d\n",LCSlength());
	}

}