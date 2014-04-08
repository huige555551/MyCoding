#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Node{
public:
	string name;
	vector<Node*> adj;
	bool visited;
	int groupId;

	Node(string str):name(str), visited(false), groupId(-1){}
	int getNeighborCount() {
		return adj.size();
	}
};

class Graph{
public:
	unordered_map<string, Node*> hashNode;
	vector<Node*> nodes;

	void createNode(string str)
	{
		Node* n = new Node(str);
		nodes.push_back(n);
		hashNode[str] = n;
	}

	bool isExist(string str)
	{
		if(hashNode.count(str)>0) return true;
		else return false;
	}

	void addEdge(string str1, string str2)
	{
		if(!isExist(str1)) createNode(str1);
		if(!isExist(str2)) createNode(str2);

		hashNode[str1]->adj.push_back( hashNode[str2] );
		hashNode[str2]->adj.push_back( hashNode[str1] );
	}

	bool isBipartite()
	{
		for(int i=0; i<nodes.size(); i++)
		{
			if(!nodes[i]->visited)
			{
				bool f = bfs(nodes[i]);
				if(!f) return false;
			}
		}

		return true;
	}
	
	bool bfs(Node* n)
	{
		n->groupId = 1;

		queue<Node*> q;
		q.push(n);

		while(!q.empty())
		{
			n = q.front(); q.pop();
			n->visited = true;

			for(int i=0; i<n->getNeighborCount(); i++)
			{
				if(!n->adj[i]->visited)
				{
					n->adj[i]->groupId = 3 - n->groupId;
					q.push(n->adj[i]);
				}
				else 
				{
					if(n->adj[i]->groupId == n->groupId)
						return false;
				}
			}
		}

		return true;
	}

	~Graph()
	{
		for(int i=0; i<nodes.size(); i++)
		{
			delete nodes[i];
		}
	}
};

int main()
{
	freopen("gcj_bad_horse_small-practice-2.in", "r", stdin);
	freopen("output.out", "w", stdout);

	int input_count;
	cin >> input_count;

	int counter = 1;
	while(input_count)
	{
		//do work
		int M;
		cin >> M;

		Graph g;
		for(int i=0; i<M; i++)
		{
			string str1, str2;
			cin >> str1 >> str2;
			g.addEdge(str1, str2);
		}
		
		cout << "Case #" << counter++ << ": " << (g.isBipartite()?"Yes":"No") << "\n";

		//finish work
		input_count--;
	}

	return 0;
}