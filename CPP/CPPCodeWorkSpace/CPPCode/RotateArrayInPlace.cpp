#include <iostream>
#include <string>
#include <vector>
using namespace std;

void rotateArrayByK(int arr[], int size, int k)
{
	reverse(arr, 0, k-1);
	reverse(arr, k, size-1);
	reverse(arr, 0, size-1);
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6};
	rotateArrayByK(arr, sizeof(arr)/sizeof(arr[0]), 2);
	return 0;
}