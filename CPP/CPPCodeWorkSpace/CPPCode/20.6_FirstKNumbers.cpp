#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int arr[] = {10, 2, 20, 30, 5, 3, 1, 25, 15, 6, 100, 200};

void swap(int arr[], int i, int j)
{
	int temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int partition(int arr[], int n, int k, int start, int end)
{
	int pivot = arr[end];

	int j = -1;
	for(int i=0; i<=end-1; i++){
		if(arr[i] <= pivot){
			j = j+1;
			swap(arr, i, j);
		}
	}
	swap(arr, j+1, end);

	return j+1;
}

void findKNumbers(int arr[], int n, int k)
{
	int start = 0;
	int end = n-1;

	while(1)
	{
		int q = partition(arr, n, k, start, end);
		
		if(q==k-1) break;
		else if(q<k-1) start = q+1;
		else end = q-1;
	}
}

//2nd method using sort
struct CompareClass{
	bool operator()(int i, int j){
		return i < j;
	}
} compareObj;

void findKSort(int arr[], int n, int k)
{
	sort(arr, arr+n, compareObj);

	for(int i=0; i<k; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 6;

	//print
	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;

	//call function
	findKNumbers(arr, n, k);	

	//print output
	for(int i=0; i<k; i++){
		cout << arr[i] << " ";
	}
	cout << endl;

	findKSort(arr, n, k);

	return 0;
}