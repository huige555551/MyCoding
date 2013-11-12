#include<stdio.h>

#define MAX 102
//#define NEG -2147483648

long input[MAX][MAX];
long cumulate[MAX];

long max(long a,long b)
{
	if(a>b) return a;
	return b;
}

void main()
{
	long NEG,row,column,i,j,k,maximum=0;

	//freopen("in.txt","r",stdin);

	while(scanf("%ld %ld",&row,&column)==2)
	{
		if(row==0 && column==0) break;

		maximum=0;
		NEG=-(row*column);

		for(i=1; i<=row; i++)
		{
			for(j=1; j<=column; j++)
			{
				scanf("%ld",&k);
				if(k==0)
					input[i][j]=input[i-1][j]+1;
				else
					input[i][j]=input[i-1][j]+NEG;
			}

			for(j=0; j<i; j++)
			{
				for(k=1; k<=column; k++)
				{
					cumulate[k]=input[i][k]-input[j][k];

					cumulate[k]=max(cumulate[k-1]+cumulate[k],cumulate[k]);

					if(cumulate[k]>maximum)
						maximum=cumulate[k];
				}
			}
		}
		printf("%ld\n",maximum);
	}
}