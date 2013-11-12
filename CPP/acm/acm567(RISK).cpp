#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
using namespace std;

#define WHITE 1
#define GRAY 2
#define BLACK 3
#define NIL -1
#define INF -99

int g[21][21];
int color[21];
int discover[21];
int parent[21];
queue<int> Q;


void get_num(char *s,int n)
{
	char t[100];
	int first,i,j,k,l;

	l=strlen(s);
	first=1;
	for(i=0; i<l; i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			j=0;
			while(s[i]>='0' && s[i]<='9')
			{
				t[j++]=s[i++];
			}
			t[j]=0;

			if(first) first=0;
			else
			{
				k=atoi(t);	
				g[n][k]=g[k][n]=1;
			}
		}
	}
}

void bfs(int source)
{
	int u,v,i;

	for(u=1; u<=20; u++)
	{
		color[u]=WHITE;
		discover[u]=INF;
		parent[u]=NIL;		
	}

	color[source]=GRAY;
	discover[source]=0;
	parent[source]=NIL;

	if(!Q.empty())
	{
		while(!Q.empty())
		{
			Q.pop();
		}
	}

	Q.push(source);

	while(!Q.empty())
	{
		u=Q.front();
		Q.pop();

		for(i=1; i<=20; i++)
		{
			if(g[u][i])
			{ 
				v=i;
				if(color[v]==WHITE)
				{
					color[v]=GRAY;
					discover[v]=discover[u]+1;
					parent[v]=u;

					Q.push(v);
				}
			}
		}
		color[u]=BLACK;
	}
}

int find_path(int start,int end)
{
	int i,count=1;

	i=end;

	while(start!=parent[i])
	{
		i=parent[i];
		count++;
	}
	return count;
}

void clear_graph()
{
	int i,j;

	for(i=1; i<=20; i++)
	{
		for(j=1; j<=20; j++)
		{
			g[i][j]=0;
		}
	}
}

void main()
{
	int i,n,ans,start,dest,test=1;
	char s[100];

	//freopen("in.txt","r",stdin);

	while(gets(s))
	{
		clear_graph();

		i=1;
		get_num(s,i);
		for(i=2; i<=19; i++)
		{
			gets(s);
			get_num(s,i);
		}

		gets(s);
		n=atoi(s);

		if(n)printf("Test Set #%d\n",test++);

		for(i=1; i<=n; i++)
		{
			gets(s);

			sscanf(s,"%d %d",&start,&dest);

			bfs(start);

			ans=find_path(start,dest);

			printf("%2d to %2d: %d\n",start,dest,ans);			
		}
		printf("\n");
	}
}