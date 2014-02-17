#include <iostream>
#include <vector>
using namespace std;

int LeastMissingNum(int arr[], int first, int last)
{
	if(last <= first) return -1;

	if(last - first == 1) 
	{
		if(arr[last] - arr[first] == 1)
			return arr[last] + 1;
		else
			return arr[first] + 1;
	}

	int mid = (last + first)/2;

	// caution: consider min in both cases
	// (first to mid) OR (mid to last)
	if(mid - first < arr[mid] - arr[first])
		LeastMissingNum(arr, first, mid);	
	else
		LeastMissingNum(arr, mid, last);
}

bool BinarySearchRecur(int arr[], int first, int last, int num)
{
	if(first > last) 
		return false;

	int mid = (last + first)/2;

	if(arr[mid] == num)
		return true;
	else if ( arr[mid] < num )
		return BinarySearchRecur(arr, mid+1, last, num);
	else 
		return BinarySearchRecur(arr, first, mid-1, num);
}

int main()
{
	int arr[] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};
	int size = sizeof(arr)/sizeof(int);
	vector<int> v(arr, arr+size);

	/*cout << BinarySearchRecur(arr, 0, size-1, 11) << endl;
	cout << BinarySearchRecur(arr, 0, size-1, 5) << endl;*/

	cout << LeastMissingNum(arr, 0, size-1) << endl;

	return 0;
}