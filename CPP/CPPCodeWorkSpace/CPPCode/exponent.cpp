#include<iostream>
using namespace std;

static int iteration = 0;

double exponent(int number, int n)
{
	int x;
	
	iteration++;
	if(n==0)
	{
		return 1;
	}
	else if (n==1)
	{	
		return number;
	}
	else if(n<0)
	{
		x = exponent(number,-n);
		return 1.0/x;
	}
	else if(n&1)//if n is odd
	{
		x = exponent(number,(n-1)/2);
		return number*x*x;
	}
	else
	{
		x = exponent(number,n/2);
		return x*x;
	}
}

int main()
{
	iteration=0;
	cout<<exponent(2,16)<<" "<<iteration<<endl;
	iteration=0;
	cout<<exponent(2,7)<<" "<<iteration<<endl;
	iteration=0;
	cout<<exponent(2,-2)<<" "<<iteration<<endl;
	iteration=0;
	cout<<exponent(2,0)<<" "<<iteration<<endl;
	iteration=0;
	cout<<exponent(2,1)<<" "<<iteration<<endl;
	
	return 0;
}
