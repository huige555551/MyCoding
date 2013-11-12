#include <iostream>
#include <vector>
using namespace std;

bool isSubsetSumRecur (int arr[], int n, int sum)
{	
	if(sum==0) return true;
	if(n==0) return false;

	if(arr[n-1] > sum) 
		return isSubsetSumRecur(arr, n-1, sum);

	return	isSubsetSumRecur(arr, n-1, sum) || 
			isSubsetSumRecur(arr, n-1, sum-arr[n-1]);
}

bool findPartiionRE (int arr[], int n)
{
	int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];

	// If sum is odd, there cannot 
	// be two subsets with equal sum
    if (sum%2 != 0) return false;

	return isSubsetSumRecur(arr, n, sum/2);
}

bool findPartiionDP (int arr[], int n)
{
	int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
	if (sum%2 != 0) return false;

	//subset sum problem below for sum/2
	vector<vector<bool>> M(n+1, vector<bool>((sum/2)+1) );

	for(int i=0; i<=n; i++) M[i][0] = true;
	for(int j=1; j<=sum/2; j++) M[0][j] = false;

	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=sum/2; j++)
		{
			if(arr[i-1] > j)
				M[i][j] = M[i-1][j];
			else{
				M[i][j] = M[i-1][j] || 
						  M[i-1][j-arr[i-1]];
			}
		}
	}

	return M[n][sum/2];
}

int main()
{
	int arr[] = {3, 1, 5, 9, 12};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout << isSubsetSumRecur(arr, n, 11) << endl;
	cout << "Balance partition possible?(RE) : " << findPartiionRE(arr, n) << endl;
	cout << "Balance partition possible?(DP) : " << findPartiionDP(arr, n) << endl;
	return 0;
}