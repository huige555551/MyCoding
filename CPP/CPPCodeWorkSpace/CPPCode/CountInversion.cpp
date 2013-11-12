#include <iostream>
#include <vector>
using namespace std;


int merge(int arr[], int left, int mid, int right)
{
	vector<int> temp;
	int count = 0;

	int i = left;
	int j = mid + 1;

	while(i<=mid && j<=right){
		if(arr[i] <= arr[right]){
			temp.push_back(arr[i++]);
		}else{
			count += (mid - i)+1;
			temp.push_back(arr[j++]);
		}
	}

	while(i<=mid){
		temp.push_back(arr[i++]);
	}
	while(j<=right){
		temp.push_back(arr[j++]);
	}

	for(int i=0; i<temp.size(); i++){
		arr[left + i] = temp[i];
	}

	return count;
}

int mergeSort(int arr[], int left, int right)
{
	int count = 0;

	if(left < right)
	{
		int mid = (left + right) / 2;
		count += mergeSort(arr, left, mid);
		count += mergeSort(arr, mid+1, right);
		count += merge(arr, left, mid, right);
	}
	return count;
}

void printArray(int arr[], int size){
	for(int i=0; i<size; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

int getInvCount(int arr[], int n)
{
  int inv_count = 0;
  int i, j;
 
  for(i = 0; i < n - 1; i++)
    for(j = i+1; j < n; j++)
      if(arr[i] > arr[j])
        inv_count++;
 
  return inv_count;
}

int main()
{
	int arr[] = {1, 20, 6, 4, 5};
	int size = sizeof(arr)/sizeof(arr[0]);
	cout << getInvCount(arr, size) << endl;

	int count = mergeSort(arr, 0, size-1);
	printArray(arr, size);
	cout << count << endl;
	
	return 1;
}