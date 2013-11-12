#include <stdio.h> 

#define MAX_N 5

int Cumulate[MAX_N + 1], Table[MAX_N + 1][MAX_N + 1];

int max(int a,int b)
{
	if(a>b)	return a;
	return b;
}

int main()
{ 
	int N,i,j,k,Max = 0;
	
	freopen("input.txt","r",stdin);

	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{ 
		for (j = 1; j <= N; j++)
		{ 
			scanf("%d", &Table[i][j]);
			Table[i][j] += Table[i - 1][j];
		} 

		for (j = 1; j < i; j++)
		{ 
			for (k = 1; k <= N; k++)
			{ 
				Cumulate[k] = Table[i][k] - Table[j][k];

				Cumulate[k] = max(Cumulate[k - 1] + Cumulate[k],Cumulate[k]);

				if (Cumulate[k] > Max)
					Max = Cumulate[k];
			} 
		} 
	} 

	printf("%d\n", Max);

	return 0;
}
