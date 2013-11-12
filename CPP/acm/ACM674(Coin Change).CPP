#include <iostream.h>

//#define MAX 30002
#define MAX 10000

int main()
{
	int n,i,v[5]={1,5,10,25,50};
	long long t[MAX+1];

	t[0]=1;

	for (i=0;i<MAX;i++)
		t[i] = 1;

	for (i=5;i<MAX;i++)
		t[i] = t[i] + t[i-5];

	for (i=10;i<MAX;i++)
		t[i]+=t[i-10];

	for (i=25;i<MAX;i++)
		t[i]+=t[i-25];

	for (i=50;i<MAX;i++)
		t[i]+=t[i-50];

	while(cin>>n)
	{
		cout << t[n] << endl;

	}

	return 0;
}

