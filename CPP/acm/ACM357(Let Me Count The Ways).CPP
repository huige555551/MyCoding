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
		if (t[n]==1)
		{
			cout << "There is only 1 way to produce " << n
					<< " cents change." << endl;
		}
		else
		{
			cout << "There are " << t[n]
					<< " ways to produce " << n
						<< " cents change." << endl;
		}
	}

	return 0;
}

/*
--|----------------------------------------------------------------------|
  | 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25  |
--|----------------------------------------------------------------------|
1:|1 1 1 1 1 1 1 1 1 1  1  1  1  1  1  1  1  1  1  1  1  1  1  1  1  1   |
--|----------------------------------------------------------------------|
5:|1 1 1 1 1 2 2 2 2 2  3  3  3  3  3  4  4  4  4  4  5  5  5  5  5  5   |
--|----------------------------------------------------------------------|
10|1 1 1 1 1 2 2 2 2 2  4  4  4  4  4  6  6  6  6  6  9  9  9  9  9  11  |
--|----------------------------------------------------------------------|
25|1 1 1 1 1 2 2 2 2 2  4  4  4  4  4  6  6  6  6  6  9  9  9  9  9  12  |
--|----------------------------------------------------------------------|
*/