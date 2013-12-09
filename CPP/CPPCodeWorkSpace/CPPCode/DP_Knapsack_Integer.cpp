#include <iostream>
#include <vector>
using namespace std;

int val[] = {41, 100, 120};
int wt[] = {10, 20, 30};
int  C = 50;

void print_int_knap(int c, vector<int>& R, vector<int>& M)
{
	if(c==0 || R[c]==-1) {
		cout << "Integer knapsack solution: \n"; 
		return;
	}

	print_int_knap(c - wt[R[c]], R, M);
	
	cout << R[c] << " ";
}

//integer knapsack problem 
//duplicate items allowed  
int knapsack_int(int value[], int weight[], int n, int C)
{
	//stores the profit for each capacity level
	vector<int> M(C+1, 0);
	//keeps track of which item number chosen for capacity c
	vector<int> R(C+1, -1);			

	//for each capacity c \in C
	for(int c=1; c<=C; c++)
	{
		M[c] = M[c-1];

		//try for each item to take with capacity c
		for(int i=0; i<n; i++)
		{
			int tmp=0;

			if (c >= weight[i])
				tmp = M[c-weight[i]] + value[i];

			if (tmp > M[c])
			{
				M[c] = tmp;
				R[c] = i;
			}
		}
	} 

	print_int_knap(C, R, M); cout << endl;

	int ans = M[C]; 
	return ans;
}

int main()
{
    int n = sizeof(val)/sizeof(val[0]);

	cout << "INTEGER KNAPSACK:" << endl;
	cout << knapsack_int(val, wt, n, C) << endl;
    return 0;
}