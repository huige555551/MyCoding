#include <iostream>
#include <queue>
#include <utility>
using namespace std;

#define INF INT_MAX
#define N 5 //row
#define M 6 //column

//input graph : very coarse implementation 
//better to use vector
int graph[N][M] = {	{0,	0,	0,	0,	0,	0},
					{2,	1,	1,	0,	1,	0},
					{1,	1,	1,	0,	1,	0},
					{1,	0,	0,	0,	0,	0},
					{1,	10,  0,	1,	1,	1}
				  };

//better to use vector
int dist[N][M];
int visited[N][M];

//initialize with distance INF and not visited
void initialize_graph(int source_r, int source_c)
{
	for(int r=0; r<N; r++) 
	{
		for(int c=0; c<M; c++) 
		{
			dist[r][c] = INF;
			visited[r][c] = 0;
		}
	}
	
	dist[source_r][source_c] = 0;
}

//find the shortest length from source to destination
//source and destination location are given as arguments
//some other extra checkings could be done
int bfs(int source_r, int source_c, int dest_r, int dest_c)
{
	initialize_graph(source_r, source_c);

	// queue with (row,col) index
	queue<pair<int, int>> q;

	q.push(make_pair(source_r, source_c));

	while(!q.empty())
	{
		pair<int, int> p = q.front(); q.pop();
		visited[p.first][p.second] = 1;
		
		for(int r=-1; r<=1; r++)
		{
			for(int c=-1; c<=1; c++)
			{
				if(r==0 && c==0) continue;			

				int row = p.first + r;
				int col = p.second + c;

				//if row & col are outside the grid
				if(row>=N || row<0) continue;
				if(col>=M || col<0) continue;

				//if there is a wall 
				if(graph[row][col]==1) continue;
				
				//if not visited yet
				if(visited[row][col]==0)
				{
					dist[row][col] = dist[p.first][p.second] + 1;
					visited[row][col] = 1;
					
					//if find the destination 
					if(row==dest_r && col==dest_c) 
						return dist[row][col];

					q.push(make_pair(row,col));
				}
			}
			
		}
	}

	return -1;
}

int main()
{
	cout << "shortest length: " << bfs(4,1, 1,0) << endl;
	return 1;
}





//0	0	0	0	0	0
//2	1	1	0	1	0
//1	1	1	0	1	0
//1	0	0	0	o	o
//1	10	1	1	1	1
//
//
//Input - nxm array
//         - starting point
//
//output - path of the shortest lenght to the gold
//
//1=wall
//0=path
//2=gold