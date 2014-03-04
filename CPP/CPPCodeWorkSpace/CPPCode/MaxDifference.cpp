#include <iostream>
#include <vector>
#include <climits>
using namespace std;
/*
Given an array arr[] of integers, find out the difference between any two elements 
such that larger element appears after the smaller number in arr[].
Examples: 
If array is [2, 3, 10, 6, 4, 8, 1] then returned value should be 8 (Diff between 10 and 2). 
If array is [ 7, 9, 5, 6, 3, 2 ]  then returned value should be 2 (Diff between 7 and 9)
*/
int maxDifference1(vector< int > a)
{
    int max = INT_MIN;

    for(int i=0; i<a.size(); i++)
    {
        for(int j=i+1; j<a.size(); j++)
        {
            int diff = a[j] - a[i];
            
            if(diff > max)
                max = diff;
        }
    }
    return max;
}

int maxDifference2(vector< int > a)
{
	//initalize max_diff 
	int max_diff = INT_MIN;
	//initialize min element
	int min_elem = a[0]; 

	for(int i=1; i<a.size(); i++)
	{
		//calculate diff with only minimum element seen so far
		int diff = a[i] - min_elem;

		if(diff > max_diff)	max_diff = diff;
		
		//only store the min element seen so far
		if(a[i] < min_elem)
			min_elem = a[i];
	}

	return max_diff;
}

int main()
{
	int a[] = {2,3,10,2,4,8,1};
	vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
	cout << maxDifference1(v) << endl;
	cout << maxDifference2(v) << endl;
	return 0;
}

/*
http://www.geeksforgeeks.org/maximum-difference-between-two-elements/
*/
