#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

void get_pair(int credit, vector<int>& input, vector<vector<int>>& values, int &a, int &b)
{
	int num_inputs = input.size();
	for(int i=0; i<num_inputs; i++)
	{
		int rest = credit - input[i];
		if(rest >= credit || rest <= 0) continue;

		if(rest == input[i])
		{
			if(values[rest].size()>=2)
			{
				a = values[rest][0];
				b = values[rest][1];
				return;
			}
		}
		else
		{		
			if(values[rest].size()!=0) 
			{
				a = i+1;
				b = values[rest][0];
				return;
			}
		}
	}
}

int main()
{
	freopen("A-large-practice.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int input_count = 0;
	cin >> input_count;

	int num_case = 1;
	while(input_count>0)
	{
		int credit;
		int num_items;
		
		cin >> credit;
		cin >> num_items;
		
		vector<int> input;
		vector<vector<int>> values(1001);

		int index = 1;
		while(num_items>0)
		{
			int tmp;
			cin >> tmp;
			
			values[tmp].push_back(index);
			input.push_back(tmp);

			num_items--;
			index++;
		}

		int a, b;
		get_pair(credit, input, values, a, b);
		
		cout << "Case #" << num_case << ": " << a << " " << b << endl;
		
		input_count--;
		num_case++;
	}

	return 0;
}