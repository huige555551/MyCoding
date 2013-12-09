#include <iostream>
using namespace std;

int main()
{
	long int testNum;
	cin>>testNum;

	while(testNum--)
	{
		long int n;
		cin >> n;

		long int nzero=0, none=0;
		long int sum=0;

		while(n!=0)
		{
			if(n&1)
			{
				sum += nzero;
			}
			else
			{
				nzero++;
			}
			n=n>>1;
		}
		
		if(sum&1)
			cout<<"First Player"<<endl;
		else 
			cout<<"Second Player"<<endl;
	}

}