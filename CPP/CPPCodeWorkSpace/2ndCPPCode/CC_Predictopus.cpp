#include <iostream>
#include <stdio.h>
using namespace std;

double predict(double p)
{
	double val = 10000.0;
	
	double sum = p*2.0*(1.0-p)*val - (1.0-p)*val;

	sum = val + sum;

	return sum;
}

int main()
{
	//freopen("in.txt", "r", stdin);

	int n;
	double p;

	cin >> n;

	while(n--){
		scanf("%lf", &p);
		printf("%lf\n", predict(p));
	}
	return 0;
}