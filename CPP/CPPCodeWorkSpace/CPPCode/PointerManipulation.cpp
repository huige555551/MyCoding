#include<iostream>
using namespace std;

void function1(int **p)
{
	for(int i=0; i<4; i++){
		cout<<p<<" "<<*p<<" "<<*(*p)<<endl;
		p++;
	}
}

void function2(const char * str)
{
	cout<<str<<endl;
}

int main()
{
	char * str = "ABC";
	str = "DBE";

	function2(str);
	/////////array of pointers/////////////
	int *p[4];
	int *p1,*p2,*p3,*p4;

	p1 = new int(10);
	p2 = new int(15);
	p3 = new int(20);
	p4 = new int(25);

	p[0]=p1;
	p[1]=p2;
	p[2]=p3;
	p[3]=p4;

	function1(p);
	//////////////////////////////////////////


	getchar();
	return 0;
}