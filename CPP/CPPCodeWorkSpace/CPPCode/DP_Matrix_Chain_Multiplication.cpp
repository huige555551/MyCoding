#include <vector>
#include <iostream>
#include <stdio.h>
#include <climits>
using namespace std;

int MatrixChainOrderRecur(int p[], int i, int j)
{
	if(i==j) return 0;

	int min = INT_MAX;
	for (int k = i; k <j; k++)
    {
        int count = MatrixChainOrderRecur(p, i, k) +
					MatrixChainOrderRecur(p, k+1, j) +
					p[i-1] * p[k] * p[j];
 
        if (count < min)
            min = count;
    }

	return min;
}

void printOrder(vector<vector<int>>& R, int i, int j)
{
	if(i==j) {
		cout << i; 
		return;
	}
	
	cout << "(";
	printOrder ( R, i, R[i][j]);
	printOrder ( R, R[i][j]+1, j);
	cout << ")";;
}

int MatrixChainOrderDP(int p[], int n)
{
	vector<vector<int>> M(n+1, vector<int>(n+1,0));
	vector<vector<int>> R(n+1, vector<int>(n+1,0));

	for (int L=2; L<=n; L++)   
    {
		for (int i=1; i<=n-L+1; i++)
        {
			int j = i+L-1;
			M[i][j] = INT_MAX;

			for (int k=i; k<j; k++)
            {
				int t = M[i][k] + M[k+1][j] + p[i-1]*p[k]*p[j];
				if(t < M[i][j]){
					M[i][j] = t;
					R[i][j] = k;
				}
			}
		}
	}

	printOrder(R, 1, n); cout << endl;

	return M[1][n];
}

int main()
{
	//size of the matrices
	//1x2, 2x3, 3x4, 4x3
    int p[] = {1, 2, 3, 4, 3};
    int n = sizeof(p)/sizeof(p[0]); // n-1 is the number of matrix
 
    printf("Minimum number of multiplications is (recursive): %d\n", MatrixChainOrderRecur(p, 1, n-1));

	printf("Minimum number of multiplications is (DP): %d\n", MatrixChainOrderDP(p, n-1));

    return 0;
}