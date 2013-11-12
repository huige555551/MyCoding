#include <stdio.h>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

ll findResult(ll r, ll t)
{
	ll a, an, n, sum, left, right, prev_left;

	a = 2*r+1;	 
	n = 1;
	sum = 0;
	left = right = prev_left = n;

	while(1)
	{
		an = a + (n-1)*4; 
		sum = n*(a + an)/2;

		if(sum >= t) break;
		
		left = n;
		n = n*2;	
	}
	right = n;

	while(left <= right)
	{
		n = (left+right)/2;

		an = a + (n-1)*4; 
		sum = n*(a + an)/2;

		if(sum > t) 
			right = n-1;
		else if (sum < t) {
			prev_left = n; 
			left = n+1;
		}
		else return n;
	}

	return prev_left;
}


int main()
{
	freopen("A-large-practice.in", "r", stdin);
	freopen("output.out", "w", stdout);

	int input_count;
	cin >> input_count;

	int counter = 1;
	while(input_count)
	{
		//do work
		ll r, t;

		cin >> r;
		cin >> t;
		
		ll result = findResult(r, t);
		cout << "Case #" << counter++ << ": " << result << "\n";

		//finish work
		input_count--;
	}

	return 0;
}