#include<stdio.h>
#include<queue>
using namespace std;

#define MAX 202
#define WHITE 0
#define BLACK 1
#define GRAY 2

int g[MAX][MAX];
int color[MAX];
int nvertices;
queue<int> Q;

int bfs()
{
	int u,v,i;

	for(u=0; u<nvertices; u++)
	{
		color[u]=GRAY;				
	}
	
	color[0]=WHITE;	

	if(!Q.empty())
	{
		while(!Q.empty())
		{
			Q.pop();
		}
	}

	Q.push(0);

	while(!Q.empty())
	{
		u=Q.front();
		Q.pop();

		for(i=0; i<nvertices; i++)
		{
			if(g[u][i])
			{
				v=i;

				if(color[v]==GRAY)
				{
					if(color[u]==WHITE)
						color[v]=BLACK;
					else 
						color[v]=WHITE;				

					Q.push(v);
				}
				else
				{
					if(color[v]==color[u])
						return 0;
				}
			}
		}		
	}
	return 1;
}

void clear_graph()
{
	int i,j;

	for(i=0; i<nvertices; i++)
	{
		for(j=0; j<nvertices; j++)
		{
			g[i][j]=0;
		}
	}
}
void main()
{
	int i,j,k,n;

	//freopen("in.txt","r",stdin);

	while(scanf("%d",&nvertices)==1)
	{
		if(nvertices==0) break;

		clear_graph();

		scanf("%d",&n);

		for(i=0; i<n; i++)
		{
			scanf("%d %d",&j,&k);

			g[j][k]=1;
			g[k][j]=1;
		}

		i=bfs();

		if(i) printf("BICOLORABLE.");
		else printf("NOT BICOLORABLE.");
		printf("\n");
	}	
}