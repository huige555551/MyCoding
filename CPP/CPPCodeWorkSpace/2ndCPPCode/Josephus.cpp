#include <iostream>
using namespace std;

int deleteKthElement(int n, int k)
{
	if(n==1) {
		cout << n << "," << k << "->" << 0 << endl;
		return 0;
	}
	else{
		int t = (deleteKthElement(n-1, k) + k) % n;
		cout << n << "," << k << "->" << t << endl;
		return t;
	}
}

int main()
{
	int n = 5;
	int k = 3;

	cout << deleteKthElement(n, k) << endl;

	return 0;
}