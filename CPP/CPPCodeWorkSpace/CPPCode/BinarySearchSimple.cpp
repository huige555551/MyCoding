#include <iostream>
#include <iomanip>
using namespace std;

int arr[] = {1, 4, 5, 8, 10, 15, 17, 20, 22, 25, 30, 33, 35, 40, 45};

int binarySearch_Found(int num)
{
	int left, right, mid;

	left = 0;
	right = sizeof(arr)/sizeof(arr[0]);

	while(left <= right){
		mid = (left + right)/2;

		if(num < arr[mid])
			right = mid-1;
		else if(num > arr[mid])
			left = mid+1;
		else return mid;
	}

	return -1;
}

int binarySearch_smaller(int num)
{
	int left, right, mid, prev=-1;

	left = 0;
	right = sizeof(arr)/sizeof(arr[0]);

	while(left <= right){
		mid = (left + right)/2;

		if(num < arr[mid])
			right = mid-1;
		else if(num > arr[mid]){
			prev = mid; //store the previous mid index on which data is less than num
			left = mid+1;
		}
		else return mid;
	}

	return (prev>=0?prev:-1);
}

int binarySearch_greater(int num)
{
	int left, right, mid, prev=-1;

	left = 0;
	right = sizeof(arr)/sizeof(arr[0]);

	while(left <= right){
		mid = (left + right)/2;

		if(num < arr[mid]){
			prev = mid;
			right = mid-1;
		}
		else if(num > arr[mid]){
			left = mid+1;
		}
		else return (prev>=0?prev:-1);
	}

	return prev;
}

int binarySearch_smaller_greater(int num)
{
	int left, right, mid, prev, after;

	left = 0;
	right = sizeof(arr)/sizeof(arr[0]);

	while(left <= right){
		mid = (left + right)/2;

		if(num < arr[mid]){
			after = mid;
			right = mid-1;
		}
		else if(num > arr[mid]){
			left = mid+1;
			prev = mid;
		}
		else return mid;
	}

	cout << prev << " " << after << endl;
	return prev;
}

void main()
{
	int n;
	
	for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++)
		cout << setw(3) << i;
	cout << endl;
	for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++)
		cout << setw(3) << arr[i];
	cout << endl;

	while(cin >> n){
		cout << binarySearch_Found(n) << " ";
		cout << binarySearch_smaller(n) << " ";
		cout << binarySearch_greater(n) << endl;

		binarySearch_smaller_greater(n); cout << endl;
	}
	
}