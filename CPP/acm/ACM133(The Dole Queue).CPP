#include<stdio.h>

#define MAX 20

void main()
{
	/*i,count for rounding counter-clockwise*/
	/*j,clock for rounding clockwise*/
	int i,j,counter,clock,a[MAX],N,k,m,index;

	while(scanf("%d %d %d",&N,&k,&m)==3)
	{
		if((N==0) && (k==0) && (m==0))
			break;
		/*make all element 0*/
		for(i=0; i<=MAX; i++)
			a[i]=0;

		i=1;
		j=N;
		index=counter=clock=0;
		/*while all index is output*/
		while(index!=N)
		{
			if((a[i]==0) && (counter!=k))
			{
				counter++;
			}

			if((a[j]==0) && (clock!=m))
			{
				clock++;
			}

			if((counter==k) && (clock==m))
			{
				a[i]=1;
				a[j]=1;
				index+=2;

				if(i==j)
				{
					index--;
					printf("%3d",i);
				}
				else
					printf("%3d%3d",i,j);

				if(index!=N)
					printf(",");

				counter=clock=0;
			}

			if(counter!=k)
			{
				i++;
				if(i==N+1)
					i=1;
			}

			if(clock!=m)
			{
				j--;
				if(j==0)
					j=N;
			}
		}
		printf("\n");
	}
}