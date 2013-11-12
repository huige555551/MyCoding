#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> get_subsets(vector<int> set, int index){
	
	vector<vector<int>> all_subset;	
	
	//if index == length of vector, then return empty set
	if(index==set.size()){			
		vector<int> empty; 
		empty.push_back(0);		
		all_subset.push_back(empty);
		return all_subset;
	}

	//get smaller subsets
	vector<vector<int>> small_subsets = get_subsets(set, index+1);

	int item = set[index];

	//get newer subsets by addding new item to all small subsets
	vector<vector<int>> new_subsets;
	for(int i=0; i<small_subsets.size(); i++){
		vector<int> subset(small_subsets[i]);
		subset.push_back(item);
		new_subsets.push_back(subset);
	}	
	
	//add all small subsets and newer subsets to all_subset
	for(int i=0; i<small_subsets.size(); i++) all_subset.push_back(small_subsets[i]);
	for(int i=0; i<new_subsets.size(); i++) all_subset.push_back(new_subsets[i]);

	return all_subset;
}

vector<vector<int>> get_subsets_by_binary(vector<int> set)
{
	vector<vector<int>> all_subsets;
	
	int num_of_subsets = 1<<set.size(); //2^size
	for(int i=0; i<num_of_subsets; i++)
	{
		vector<int> subset;
		int k=i;
		int count=0;

		while(k)
		{
			if(k&1)	subset.push_back(set[count]);
			k = k>>1;
			count++;
		}

		if(i==0) subset.push_back(0);
		all_subsets.push_back(subset);
	}

	return all_subsets;
}

void main()
{
	int num_array[] = {1,2,3};
	vector<int> set (num_array, num_array+sizeof(num_array)/sizeof(int));
	for(int i=0; i<set.size(); i++) cout << set[i] << endl;

	vector<vector<int>> a;
	a = get_subsets(set,0);
	for(int i=0; i<a.size(); i++) {
		for(int j=0; j<a[i].size(); j++){
			if(a[i][j]) 
				cout << a[i][j];
		}
		cout << endl;
	}

	a = get_subsets_by_binary(set);
	for(int i=0; i<a.size(); i++) {
		for(int j=0; j<a[i].size(); j++){
			cout << a[i][j];
		}
		cout << endl;
	}
}