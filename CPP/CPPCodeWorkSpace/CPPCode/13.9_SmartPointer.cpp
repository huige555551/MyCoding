#include <iostream>
using namespace std;

class Person{
    int age;
    char* pName;
 public:	 
    Person(): pName(0),age(0) {}
    Person(char* pName, int age): pName(pName), age(age) {}
	~Person() {}

    void Display() {
        printf("Name = %s Age = %d \n", pName, age);
    }
        
	void Shout() {
        printf("Ooooooooooooooooo");
    } 
};

//template <typename T>
template <class T>
class SP{
	T* ptr;
	int* refCount;
public:
	
	SP(): ptr(0), refCount(0) {}

	//constructor
	SP(T* ptrData) {
		ptr = ptrData;
		refCount = new int();
		*refCount = 1;
	}	

	//destructor
	~SP(){
		--*refCount;

		if(*refCount==0)
		{
			delete ptr;
			delete refCount;

			ptr = 0;
			refCount = 0;
		}
	}

	//copy constructor
	SP(const SP<T>& obj)
	{
		ptr = obj.ptr;
		refCount = obj.refCount;
		++*refCount;
	}

	//assignment operator
	SP<T>& operator=(const SP<T>& obj)
	{
		if(this != &obj){
			ptr = obj.ptr;
			refCount = obj.refCount;
			++*refCount;
		}

		return *this;
	}

	T* operator->() {
		return ptr;
	}

	T& operator*() {
		return *ptr;
	}	
};

void main()
{
	//no problem of dangling pointer
	SP<Person> p(new Person("Scott", 25));
    p->Display();
    {
		//call copy constructor 
        SP<Person> q = p;
        q->Display();
        // Destructor of Q will be called here..

		//call assignment operator
		SP<Person> r;
		r = p;
        q->Display();
		//Destructor called for r
    }
    p->Display();
}

//source link:
//http://www.codeproject.com/Articles/15351/Implementing-a-simple-smart-pointer-in-c
