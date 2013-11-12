#include<iostream>
using namespace std;

int fibonacciSequence(int n, int &Fprev, int &Fcurr)
{
	int curr,prev;
	
	if(n==1)
	{
		Fprev=0;
		Fcurr=1;
	}
	else
	{
		fibonacciSequence(n/2,Fprev,Fcurr);
		prev = Fcurr*Fcurr + Fprev*Fprev;
		curr = Fcurr*(Fcurr+2*Fprev);		
		
		if(n&1)//if n is odd
		{	
			Fprev=curr;
			Fcurr=curr+prev;
		}
		else
		{
			Fprev=prev;
			Fcurr=curr;
		}
	}
	return Fcurr;
}

int fibonacci(int n){
	int a,b;
	return fibonacciSequence(n,a,b);
}

int M[2][2]={{1,1},{1,0}};

int fib(int n)
{

	return 0;
}

int main()
{
	cout << M[0][0] << " " << M[0][1] << endl;
	cout << M[1][0] << " " << M[1][1] << endl;

	int n=0;
	cout<<"Enter the fibonacci sequence : ";
	cin>>n;
	cout<<endl<<fibonacci(n)<<endl;
	return 0;
}
