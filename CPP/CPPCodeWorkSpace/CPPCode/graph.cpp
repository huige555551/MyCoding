#include<iostream>
#include<vector>
#include<utility>
#include<fstream>
#include<sstream>
#include<string>
#include<climits>
#include<queue>
#include<stack>
using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define NIL -1
#define INF INT_MAX

vector<vector<int>> adj;
vector<int> parent;
vector<int> color;

//bfs
vector<int> dist;

//dfs
vector<int> discover;
vector<int> final;

void bfs(int source)
{
	for(int i=0; i<adj.size(); i++){
		color.push_back(WHITE);
		parent.push_back(NIL);
		dist.push_back(INF);
	}

	color[source]=GRAY;
	parent[source]=NIL;
	dist[source]=0;

	queue<int> Q;

	Q.push(source);

	while(!Q.empty())
	{
		int u = Q.front(); Q.pop();
		for(auto v=adj[u].begin(); v!=adj[u].end(); v++)
		{
			if(color[*v]==WHITE)
			{
				parent[*v]=u;
				color[*v]=GRAY;
				dist[*v] = dist[u]+1;
				Q.push(*v);
			}
		}
		color[u]=BLACK;
	}

	for(int i=0; i<parent.size(); i++) cout << dist[i] << " "; cout << endl;
	for(int i=0; i<parent.size(); i++) cout << parent[i] << " "; cout << endl;
}

void dfs_stack()
{
	color.clear(); discover.clear(); final.clear(); parent.clear();

	for(int i=0; i<adj.size(); i++){
		color.push_back(WHITE);
		parent.push_back(NIL);
		discover.push_back(0);
		final.push_back(0);
	}

	int time=0;

	for(int i=0; i<adj.size(); i++)
	{
		if(color[i]!=WHITE) continue;

		stack<int> S;
		S.push(i);

		while(!S.empty())
		{
			int u = S.top(); S.pop();
		
			//if it is not discoverd yet
			if(color[u]==WHITE)
			{
				time=time+1;
				discover[u]=time;
				color[u]=GRAY; 
				S.push(u);			  //again put it in stack for getting final time

				//stack up the childrens to be explored
				for(auto v=adj[u].begin(); v!=adj[u].end(); v++)
				{
					if(color[*v]==WHITE)
					{
						parent[*v]=u; //last parent will be remained				
						S.push(*v);	  
					}
				}
			}
			//if it has already discovered
			else if(color[u]==GRAY)
			{
				time=time+1;
				final[u]=time;
				color[u]=BLACK;
			}
		}
	}

	//print values
	for(int i=0; i<discover.size(); i++) cout << discover[i] << " "; cout << endl;
	for(int i=0; i<final.size(); i++) cout << final[i] << " "; cout << endl;
	for(int i=0; i<parent.size(); i++) cout << parent[i] << " "; cout << endl;
}


//for recursive dfs time should be global
int time=0;
void dfs_visit(int u)
{
	time=time+1;
	discover[u]=time;
	color[u]=GRAY; 
	
	for(auto v=adj[u].begin(); v!=adj[u].end(); v++)
	{
		if(color[*v]==WHITE)
		{
			parent[*v]=u;
			dfs_visit(*v);
		}
	}

	time=time+1;
	final[u]=time;
	color[u]=BLACK;
}

void dfs_recursive()
{
	color.clear(); discover.clear(); final.clear(); parent.clear();

	for(int i=0; i<adj.size(); i++){
		color.push_back(WHITE);
		parent.push_back(NIL);
		discover.push_back(0);
		final.push_back(0);
	}
	int time=0;

	for(int i=0; i<adj.size(); i++)
	{
		if(color[i]!=WHITE) continue;
		dfs_visit(i);
	}

	//print values
	for(int i=0; i<discover.size(); i++) cout << discover[i] << " "; cout << endl;
	for(int i=0; i<final.size(); i++) cout << final[i] << " "; cout << endl;
	for(int i=0; i<parent.size(); i++) cout << parent[i] << " "; cout << endl;
}

int main()
{
	vector<int> v;
	ifstream infile("dir_graph.txt");
	string str;
	while(getline(infile, str)){
		stringstream strstream(str);
		int a;
		while(strstream >> a)
		{
			v.push_back(a);
		}
		adj.push_back(v);
		v.clear();
	}

	//bfs(1);
	dfs_stack();
	dfs_recursive();

	return 0;
}