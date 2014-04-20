#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

double findResult()
{
	double C, F, X;
	cin >> C >> F >> X;

	if(X <= C) return X/2.0;
	
	double prev = X/2.0;
	double curr = prev;
	double max = prev;

	double a=0, b=0;
	int i=0;
	while( curr <= max ) {
		prev = curr;

		a += C/(2.0 + i*F);
		b = X/(2.0 + (i+1.0)*F);

		curr = a+b;
		if(prev < curr) break;
		i++;
	}

	return prev;
}


int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("output.out", "w", stdout);

	int input_count;
	cin >> input_count;

	int counter = 1;
	while(input_count)
	{
		cout << std::fixed;
		cout.precision(7);
		cout << "Case #" << counter++ << ": " << findResult() << "\n";

		//finish work
		input_count--;
	}

	return 0;
}