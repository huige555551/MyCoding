#include<iostream>
using namespace std;

int returnMax(int a, int b)
{
	int c = a-b;
	int k = (c>>31)&1;
	return (a - k*c);
}

void main()
{
	cout << returnMax(2,8) << endl;
}