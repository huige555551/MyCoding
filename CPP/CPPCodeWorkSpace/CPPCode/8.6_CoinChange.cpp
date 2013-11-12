#include <iostream>
#include <vector>
using namespace std;

int makeChange(int n, int denom) 
{
	int next_denom = 0;
	
	if(denom==25) next_denom = 10;
	if(denom==10) next_denom = 5;
	if(denom==5) next_denom = 1;
	if(denom==1) return 1;

	int ways = 0;
	
	for (int i = 0; i * denom <= n; i++) {
		//ways += makeChange(n - i * denom, next_denom);
		int t = makeChange(n - i * denom, next_denom);
		ways = ways + t;
	}
	return ways;
}

int coin_change_dynamic(int n){
	
	vector<int> t(n+1,0);
	int i;

	t[0]=1;

	//using coin 1
	for(i=0; i<=n; i++) t[i]=1;

	//using coin 5
	for(i=5; i<=n; i+=1) t[i] += t[i-5];

	//using coin 10
	for(i=10; i<=n; i+=1) t[i] += t[i-10];

	//using coin 25
	for(i=25; i<=n; i+=1) t[i] += t[i-25];

	return t[n];
}

void main()
{	
	for(int n=0; n<=100; n++){ cout << n << ": ";
		cout <<  makeChange(250, 25) << " ";
		cout << coin_change_dynamic(n) << endl;	
	}
}