#include <iostream>
#include <vector>
using namespace std;
#define INF INT_MAX

#define MAXIMUM(a,b) a>b?a:b

int arr[] = {2, -8, 3, -2, 4, -10};
int sumArr[100];

void printSequence(int maxFirstIndex, int maxLastIndex)
{
	cout << "MaxContSeq: ";
	for(int i=maxFirstIndex; i<=maxLastIndex; i++)
		cout << arr[i] << " ";	
	cout << endl;
}

int maxcontsubseq(int size)
{
	int maxSum=0;	 
	int maxLastIndex=0; 
	int maxFirstIndex=0;
	int firstIndex = 0;	

	maxSum = sumArr[0] = arr[0];	
	for(int i=1; i<size; i++)
	{
		//int a = sumArr[i-1] + arr[i];	//int b = arr[i];
		sumArr[i] = MAXIMUM(sumArr[i-1] + arr[i], arr[i]);		
		
		//if(sumArr[i] < 0) firstIndex = i+1;
		if(sumArr[i] == arr[i]) firstIndex = i;

		//store the index of sequence
		if(maxSum < sumArr[i]) {
			maxFirstIndex = firstIndex;
			maxSum = sumArr[i];
			maxLastIndex = i;
		}
	}

	printSequence(maxFirstIndex, maxLastIndex);
	return maxSum;
}

int main()
{	
	int size = (int) sizeof(arr)/sizeof(arr[0]);
	cout << "MaxSum: " << maxcontsubseq(size) << endl;
	return 1;
}