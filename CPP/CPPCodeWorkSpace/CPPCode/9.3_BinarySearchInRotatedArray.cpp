#include <vector>
#include <iostream>
using namespace std;

int binarySearch(int x, int A[], int size)
{
	int l = 0;
	int u = size - 1;
	int m;

	while(l<=u)
	{
		m = (l+u)/2;

		if(x == A[m]) 
			return m;

		// if first half is in sorted order
		if(A[l] <= A[m])
		{
			if(x >= A[l] && x <= A[m])
				u = m-1;
			else
				l = m+1;

		}
		// else 2nd half is in sorted order
		else //if(A[m] <= A[u])
		{
			if(x >= A[m] && x <= A[u])
				l = m+1;
			else
				u = m-1;
		}
	}

	return -1;
}

int binarySearch_recursion(int x, int A[], int l, int u)
{
	if(u < l)
		return -1;
	
	int m = (l+u)/2;

	if(x == A[m]) 
		return m;

	// if first half is in sorted order
	if(A[l] <= A[m])
	{
		if(x >= A[l] && x <= A[m])
			return binarySearch_recursion(x, A, l, m-1);
		else
			return binarySearch_recursion(x, A, m+1, u);

	}
	// else 2nd half is in sorted order
	else //if(A[m] <= A[u])
	{
		if(x >= A[m] && x <= A[u])
			return binarySearch_recursion(x, A, m+1, u);
		else
			return binarySearch_recursion(x, A, l, m-1);
	}
}

void main()
{
	//int A[] = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
	int A[] = { 7, 10, 14, 15, 16, 19, 20, 25, 1, 3, 4, 5};
	int size = sizeof(A)/sizeof(A[0]);

	for(int i=0; i < size; i++)
		cout << A[i] << "->" << binarySearch(A[i], A, size) << endl;

	cout << "\n";

	for(int i=0; i < size; i++)
		cout << A[i] << "->" << binarySearch_recursion(A[i], A, 0, size-1) << endl;
}