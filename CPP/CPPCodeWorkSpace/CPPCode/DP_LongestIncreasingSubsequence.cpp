#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int LIS(int* arr, int n)
{
	vector<int> M(n, 1);  
	vector<int> R(n, -1); // for printing the sequence

	int max = 0;
	int maxLastIndex = 0;

	for(int i=1; i<n; i++)
	{
		for(int j=0; j<i; j++)
		{
			if(arr[j] < arr[i] && M[j]+1 > M[i]){
				M[i] = M[j] + 1;
				R[i] = j;
			}
		}

		if(max < M[i]){
			max = M[i];
			maxLastIndex = i;
		}
	}

	// print the sequence
	for(int i = maxLastIndex; i>=0; ){
		cout << arr[i] << " ";
		i = R[i];
	}
	cout << "\n";

	return max;
}

int findPos(vector<stack<int>> vs, int a)
{	
	for(int i = 0; i<vs.size(); i++)
	{
		if(vs[i].top() > a)
			return i;
	}

	return vs.size();
}

bool compless(const stack<int>& x, const stack<int>& y)
{
    return x.top() < y.top();
}

int LIS2(int* arr, int n)
{
	vector<stack<int>> vs;
	vector<stack<int>>::iterator it;
	vector<int> r;

	for(int i=0; i<n; i++)
	{
		//push the item in a new stack
		stack<int> newStack;
		newStack.push(arr[i]);

		//find position by binary search though the array of stacks
		it = lower_bound(vs.begin(), vs.end(), newStack, compless);

		//if not found any position
		if(it == vs.end()) {
			vs.push_back(newStack); //push a new stack into vector
			r.push_back(arr[i]);
		}
		else
			it->push(arr[i]);		//else push into specified stack
	}

	//print the sequence
	for(int i=0; i<r.size(); i++)
		cout << r[i] << " ";
	cout << endl;

	return vs.size();
}

int main()
{	
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
	int size = (int) sizeof(arr)/sizeof(arr[0]);

	cout << "LIS: " << LIS(arr, size) << endl;
	cout << "LIS: " << LIS2(arr, size) << endl;

	return 1;
}

