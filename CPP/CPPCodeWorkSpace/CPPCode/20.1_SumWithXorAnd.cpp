#include <iostream>
using namespace std;

int sum(int a, int b)
{
	if(b==0) return a;
	if(a==0) return b;
	return sum(a^b, (a&b)<<1);
}

int sum2(int a, int b)
{
	if(b==0) return a;
	if(a==0) return b;

	while(a!=0 && b!=0){
		int c = (a^b);
		int d = (a&b)<<1;
		a=c;
		b=d;
	}

	return a;
}

void main()
{
	cout << sum(3, 205) << endl;
	cout << sum2(3, 205) << endl;
}