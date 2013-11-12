//http://www.geeksforgeeks.org/dynamic-programming-set-31-optimal-strategy-for-a-game/


#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b)  {    return a > b ? a : b;  }
int min(int a, int b)  {    return a < b ? a : b;  }

int optimalStrategyOfGameRecursive(int arr[], int size, int left, int right)
{
	if(left==right) return arr[left];
	if(right==left+1) return max(arr[left], arr[right]);

	return max(arr[left] + min(optimalStrategyOfGameRecursive(arr, size, left+2, right), 
						       optimalStrategyOfGameRecursive(arr, size, left+1, right-1)
				              )
			   ,
		       arr[right] + min(optimalStrategyOfGameRecursive(arr, size, left, right-2), 
						        optimalStrategyOfGameRecursive(arr, size, left+1, right-1)
				               )
			  );
}


int optimalStrategyOfGameDP(int arr[], int size)
{
	vector<vector<int>> M(size, vector<int>(size));

	for(int gap=0; gap<size; gap++){
		for(int i=0; i<size-gap; i++){
			int j=i+gap;

			int x = 0, y = 0, z = 0;

			if(i+2 <= j) x = M[i+2][j];
			else x = 0;

			if(i+1 <= j-1) y = M[i+1][j-1];
			else y = 0;

			if(i <= j-2) z = M[i][j-2];
			else z = 0;

			
			M[i][j] = max( arr[i] + min(x,y),
						   arr[j] + min(y,z)
						 );

			cout << i << " " << j << "->" << M[i][j] << endl;
		}
	}

	return M[0][size-1];
}

int optimalStrategyOfGame(int arr[], int size)
{
	return optimalStrategyOfGameDP(arr, size);
	return optimalStrategyOfGameRecursive(arr, size, 0, size-1);
}

int main()
{
    int arr1[] = {8, 15, 3, 7};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    printf("%d\n", optimalStrategyOfGame(arr1, n));
 
    int arr2[] = {2, 2, 2, 2};
    n = sizeof(arr2)/sizeof(arr2[0]);
    printf("%d\n", optimalStrategyOfGame(arr2, n));
 
    int arr3[] = {20, 30, 2, 2, 2, 10};
    n = sizeof(arr3)/sizeof(arr3[0]);
    printf("%d\n", optimalStrategyOfGame(arr3, n));
 
    return 0;
}

/*
Output:
22
4
42
*/