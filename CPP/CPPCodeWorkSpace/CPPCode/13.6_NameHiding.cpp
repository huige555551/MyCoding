#include <iostream>
using namespace std;

class FirstClass 
{
 public:
	virtual void MethodA (int);
	virtual void MethodA (int, int);
};

void FirstClass::MethodA (int i) {
	std::cout << "ONE!!\n";
}
void FirstClass::MethodA (int i, int j) {
	std::cout << "TWO!!\n";
}

class SecondClass : public FirstClass 
{
 public:
	 void MethodA (int);
};

 void SecondClass::MethodA (int i) {
	//FirstClass::MethodA(i);
 }
 
 void main () 
 {
	SecondClass a;
	a.MethodA (1);
	
	//a.MethodA (1, 1); 
	
	//the second call won’t work, since the two-parameter MethodA is not visible. 
	//That is name hiding.
 }