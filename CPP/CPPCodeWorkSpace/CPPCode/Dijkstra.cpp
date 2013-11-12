#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

#define INF INT_MAX
#define NIL -1


class Edge
{
public:
	int outNode;
	double cost;
};

class Node
{
public:
	int id;
	vector<Edge> edges;
	int via;
	int prev;
	double cost;

	explicit Node(int n){
		id = n;
		edges.clear();
		via = NULL;
		cost = INF;
	}

};

class comparator{
public:
	bool operator()(const Node & a, const Node & b){
		return a.cost>b.cost;
	}
};

vector<Node> nodes;

void dijkstra()
{
	for(int i=0; i<nodes.size(); i++)
	{
		nodes[i].cost=INF;
		nodes[i].via=NIL;
	}
	nodes[0].cost=0;

	//to keep track which node is in solution vector
	vector<int> S(nodes.size(),-1);

	priority_queue<Node, vector<Node>, comparator> Q;
	Q.push(nodes[0]);

	while(!Q.empty()){
		Node n = Q.top(); Q.pop();
		int u = n.id;

		//this line saves the day
		//if u is already in solution, continue
		if(S[u]!=-1) continue;
		
		S[u] = n.cost;

		for(int i=0; i<nodes[u].edges.size(); i++)
		{
			int v = nodes[u].edges[i].outNode;
			if(nodes[v].cost > nodes[u].cost + nodes[u].edges[i].cost)
			{
				nodes[v].cost = nodes[u].cost + nodes[u].edges[i].cost;	
				nodes[v].via = u;
				Q.push(nodes[v]);
			}
		}
	}

	for(int i=0; i<S.size(); i++) cout << S[i] << " "; cout << endl;
	for(int i=0; i<S.size(); i++) cout << nodes[i].via << " ";
}


int main()
{
	ifstream infile("dijkstra_input.txt");
	string str;
	int count=0;

	while(getline(infile, str))
	{
		stringstream strstream(str);
		Node n(count++);
		int a;
		while(strstream >> a)
		{
			Edge e; e.outNode=a; 
			strstream>>e.cost;
			n.edges.push_back(e);
		}
		nodes.push_back(n);
	}		

	dijkstra();

	return 0;
}