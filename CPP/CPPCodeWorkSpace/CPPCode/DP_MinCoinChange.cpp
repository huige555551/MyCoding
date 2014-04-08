#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int coins[] = {1, 3, 4, 5};

int min_coin_change(int j, int numOfCoins)
{
	//return -1 to make the sum = 0; 
	//so this way of changing is not possible
	if(j < 0) return -1; 

	//return 0 to make the sum = 1
	//so this way of changing is possible
	if(j == 0) return 0; 

	int min = INT_MAX;
	for(int i=0; i<numOfCoins; i++)
	{
		int temp = min_coin_change(j - coins[i], numOfCoins) + 1;
		//if temp is not zero and temp is less than min
		if(temp && min > temp) min = temp;
	}

	//if there is no solution
	if(min == INT_MAX) return 0;

	return min;
}

int DP_min_coin_change(int V, int numOfCoins)
{
	vector<int> M(V+1, INT_MAX);
	
	M[0] = 0; //0 is possible with 0 coins
	for(int j=1; j<=V; j++)
	{
		for(int i=0; i<numOfCoins; i++)
		{
			if(coins[i] <= j) 
			{
				int temp = M[j - coins[i]] + 1;
				if (temp < M[j]) M[j] = temp;
			}
		}
	}

	//if there is no solution
	if(M[V] == INT_MAX) return 0;

	return M[V];
}

int main()
{
    int n = sizeof(coins)/sizeof(coins[0]);
	cout << min_coin_change(7, n) << endl;
	cout << DP_min_coin_change(7, n) << endl;
    return 0;
}