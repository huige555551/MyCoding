#include <vector>
#include <iostream>
using namespace std;

//int A[] = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
int A[] = { 7, 10, 14, 15, 16, 19, 20, 25, 1, 3, 4, 5};

int binarySearch(int x)
{
	int l = 0;
	int u = sizeof(A)/sizeof(A[0]) - 1;
	int m;

	while(l<=u)
	{
		m = (l+u)/2;

		if(x==A[m]) return m;

		else if(A[m] >= A[l] && A[m] <= A[u]){
			if(x < A[m]) u = m-1;
			else l = m+1;
		}
		else if(A[m] >= A[u]){
			if(x >= A[l] && x < A[m]) u = m-1;
			else l = m+1;
		}
		else if(A[m] <= A[l]){
			if(x >= A[l]) u = m-1;
			else l = m+1;
		}
	}

	return -1;
}

void main()
{
	for(int i=0; i<sizeof(A)/sizeof(A[0]); i++)
		cout << A[i] << "->" << binarySearch(A[i]) << endl;
}