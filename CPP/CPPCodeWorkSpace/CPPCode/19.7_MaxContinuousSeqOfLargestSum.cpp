#include <iostream>
#include <vector>
using namespace std;

void ContinuousSequenceOfLargestSum(vector<int> v)
{
	int sum=0;
	int max_sum=0;

	int max_last_index=0; 
	int max_first_index=0;

	int first_index=0;

	for(int i=0; i<v.size(); i++)
	{
		sum += v[i];
		if(sum<0) 
		{
			sum=0;
			first_index = i+1;
		}
		if(max_sum<sum) 
		{
			max_sum=sum;
			max_first_index = first_index;
			max_last_index = i;
		}
	}

	cout << max_sum << endl << "first: " << max_first_index << "\tlast: " << max_last_index << endl;
}

void main()
{
	int a[] = {-2, 8, 3, -2, 4, -10};
	vector<int> v(a, a+sizeof(a)/sizeof(int));

	for(auto i=v.begin(); i!=v.end(); i++) cout << *i << " "; cout << endl;
	ContinuousSequenceOfLargestSum(v);
}