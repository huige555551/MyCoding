#include <iostream>
using namespace std;

class Base 
{
 public:
	Base() { cout << "Base Constructor " << endl; }
	//~Base() { cout << "Base Destructor " << endl; }
	virtual ~Base() { cout << "Base Destructor " << endl; }

	virtual void f(){ cout << "Base Function" << endl; }
};

class Derived: public Base {
 public:
	Derived() { cout << "Derived Constructor " << endl; }
	~Derived() { cout << "Derived Destructor " << endl; }

	void f(){ cout << "Derived Function" << endl; }
};

void main() 
{
	Base *p = new Derived();
	p->f();
	delete p;
}