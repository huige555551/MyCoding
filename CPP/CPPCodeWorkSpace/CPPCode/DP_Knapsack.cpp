#include <iostream>
#include <vector>
using namespace std;

int val[] = {60, 100, 120};
int wt[] = {10, 20, 30};
int  W = 50;

int max(int a, int b) { return (a > b)? a : b; }

int knapsack(int i, int j)
{
	if (i==0 || j==0) return 0; //there is a problem: i=0 acceptable

	if (wt[i-1] > j)
       return knapsack(i-1, j);
	
	int ithInclude = val[i-1] + knapsack(i-1, j-wt[i-1]);
	int ithExclude = knapsack(i-1, j);

	return max(ithInclude, ithExclude);
}
 
// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
   // Base Case
   if (n == 0 || W == 0)
       return 0;
 
   // If weight of the nth item is more than Knapsack capacity W, then
   // this item cannot be included in the optimal solution
   if (wt[n-1] > W)
       return knapSack(W, wt, val, n-1);
 
   // Return the maximum of two cases: (1) nth item included (2) not included
   else return max( val[n-1] + knapSack(W-wt[n-1], wt, val, n-1),
                    knapSack(W, wt, val, n-1)
                  );
}

int H[100][100];

int knapsack_dynamic(int N, int W)
{
	int i, w;
	vector<vector<int>> K(N+1, vector<int>(W+1));
	//vector<vector<int>> H(N+1, vector<int>(W+1));
 
	// Build table K[][] in bottom up manner
	for (i = 0; i <= N; i++)
	{
		for (w = 0; w <= W; w++)
		{
			if (i==0 || w==0)
				K[i][w] = 0;
			else if (wt[i-1] <= w)
			{
				int a = val[i-1] + K[i-1][w-wt[i-1]];
				int b = K[i-1][w];
				K[i][w] = max(a, b);
				
				if(a>b) H[i][w] = 1;
				else H[i][w] = 0;
			}
			else{
				K[i][w] = K[i-1][w];
				H[i][w] = 0;
			}
		}
	}
 
	return K[N][W];
}

void print(int n, int w)
{
	if(n==0||w==0) return;

	if(H[n][w]==0)
	{
		print(n-1,w);
		//cout << n << "-> NO" << endl;
	}
	else {
		print(n-1,w-wt[n-1]);
		cout << n << endl; //"-> YES" << endl;
	}
}

void print_int_knap(int c, vector<int>& backtrack, vector<int>& R, vector<int>& M){
	if(c==0) {cout << "Integer knapsack solution: \n"; return;}
	print_int_knap(backtrack[c], backtrack, R, M);
	
	if(M[c]!= M[c-1]){
		cout << R[backtrack[c]] << " ";
	}
}

//integer knapsack problem 
//duplicate items allowed  
int knapsack_int(int value[], int weight[], int n, int C)
{
	vector<int> M(C+1, 0);			
	vector<int> R(C+1, -1);			//which item number chosen for capacity c \in 0..C
	vector<int> backtrack(C+1, 0);  //indicate the previous point of solution

	int i, j, tmp=0, pos;

	for(i=1; i<=C; i++)
	{
		M[i] = M[i-1];
		pos = i-1;

		for(j=0; j< n; j++)
		{
			if (i >= weight[j])
				tmp = M[i-weight[j]] + value[j];

			if (tmp > M[i])
			{
				M[i] = tmp;
				pos = i - weight[j];
				R[pos] = j;
			}
		}
		backtrack[i] = pos;
	} 

	//for(int i=0; i<backtrack.size(); i++) cout << backtrack[i] << " "; cout << endl;
	//for(int i=0; i<=C; i++) cout << R[i] << " "; cout << endl;

	print_int_knap(C, backtrack, R, M); cout << endl;

	int ans = M[C];
	//delete[] M;      
	return ans;
}

int main()
{
    int n = sizeof(val)/sizeof(val[0]);
	cout << knapsack(n, W) << endl;
    cout << knapSack(W, wt, val, n) << endl;
	cout << knapsack_dynamic(n,W) << endl;
	print(n, W);

	cout << "INTEGER KNAPSACK:" << endl;
	cout << knapsack_int(val, wt, n, W) << endl;
    return 0;
}