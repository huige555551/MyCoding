#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;

/*
Input:
k = 3, n =  4
arr[][] = { {1, 3, 5, 7},
            {2, 4, 6, 8},
            {0, 9, 10, 11}} ;

Output: 0 1 2 3 4 5 6 7 8 9 10 11 
*/

#define N 4

class Node{
public:
	int num;
	int kth;
	int count;

	Node(int n, int k, int c): num(n), kth(k), count(c){}
};

class Comparison{
	bool reverse;
public:
	Comparison(bool isGreater = false)
	{
		reverse = isGreater;
	}

	bool operator() (const Node& a, const Node& b) const
	{
		if(reverse) 
			return (a.num > b.num);
		else
			return (a.num < b.num);
	}
};

vector<int> mergeKArrays(int arr[][N], int k)
{
	//priority queue is by default MAX_HEAP with MIN(<) comarison
	//MIN_HEAP needs to have sort cass different (>)
	priority_queue<Node, vector<Node>, Comparison> queue ( Comparison(true) );
	vector<int> result;

	for(int i=0; i<k; i++)
	{
		Node node(arr[i][0], i, 1);
		queue.push(node);
	}

	while(!queue.empty())
	{
		Node node = queue.top();
		queue.pop();

		result.push_back(node.num);
		
		if(node.count < N)
		{
			Node node1(arr[node.kth][node.count], node.kth, node.count+1);
			queue.push(node1);
		}
	}

	return result;
}

int main()
{
    /*int arr[][N] =  {{2, 6, 12, 34},
                     {1, 9, 20, 1000},
                     {23, 34, 90, 2000}
					};*/
	int arr[][N] = { {1, 3, 5, 7},
					 {2, 4, 6, 8},
					 {0, 9, 10, 11}} ;

    int k = sizeof(arr)/sizeof(arr[0]);
 
    vector<int> output = mergeKArrays(arr, k);
 
    cout << "Merged array is " << endl;
    for(int i=0; i<output.size(); i++)
		cout << output[i] << " ";
 
    return 0;
}