#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int findResult()
{
	return 0;
}


int main()
{
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);

	int input_count;
	cin >> input_count;

	int counter = 1;
	while(input_count)
	{
		int result = findResult();
		cout << "Case #" << counter++ << ": " << result << "\n";

		//finish work
		input_count--;
	}

	return 0;
}