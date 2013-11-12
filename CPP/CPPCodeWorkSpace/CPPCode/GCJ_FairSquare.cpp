#include <stdio.h>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

long long int getRev(long long int n)
{
	long long int rev = 0;

	while(n){
		int d = n%10;
		n = n/10;
		rev = rev*10 + d;
	}

	return rev;
}

bool checkPalin(long long int n)
{
	long long int rev = getRev(n);
	if(n==rev) return true;
	else return false;
}

int findResult(long long int a, long long int b)
{
	long long int counter = 0;
	long long int limit = (long long int) sqrt((long double)b);
	long long int i;

	for(i=limit; i*i>=a; i--)
	{
		if(checkPalin(i)) {
			if(checkPalin(i*i))
				counter++;
		}		
	}

	return counter;
}

int main()
{
	freopen("C-large-1.in", "r", stdin);
	freopen("C-large-1.out", "w", stdout);

	int input_count;
	cin >> input_count;

	int counter = 1;
	while(input_count)
	{
		//do work
		long long int a, b;

		cin >> a;
		cin >> b;
		
		int result = findResult(a, b);
		cout << "Case #" << counter++ << ": " << result << "\n";

		//finish work
		input_count--;
	}

	return 0;
}