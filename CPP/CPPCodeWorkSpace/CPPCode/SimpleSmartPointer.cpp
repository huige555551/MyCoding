#include <iostream>
using namespace std;

//Simple smart pointer:
//for automatically deleting an allocated object
template <class T>
class SP{
	T* ptr;
 public:	
	SP(T* ptrData) {
		ptr = ptrData;
	}

	~SP() {
		delete ptr;
	}

	//return pointer
	T* operator->() {
		return ptr;
	}

	//return reference
	T& operator*() {
		return *ptr;
	}
};

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
        printf("Ooooooooooooooooo\n");
    } 
};

int main()
{
	//without smart pointer:
    Person* pPerson  = new Person("Scott", 25);
    pPerson->Display();
    delete pPerson;

	//with smart pointer: don't need to delete object
	SP<Person> p(new Person("Smart", 30));
    p->Display();
	(*p).Shout();

	//************************
	//problem: Dangling pointer
	SP<Person> dp(new Person("Dang", 25));
    dp->Display();
    {
        SP<Person> q(dp); //  or SP<Person> q = dp;
        q->Display();
        // Destructor of q will be called here..
    }
    dp->Display();
	//**see SmartPointer.cpp//

	return 0;
}

/*
Look what happens here. p and q are referring to the same Person class pointer. Now when q goes out of scope, the destructor of q will be called which deletes the Person class pointer. Now we cannot call p->Display(); since p will be left with a dangling pointer and this call will fail. (Note that this problem would have existed even if we were using normal pointers instead of smart pointers.) We should not delete the Person class pointer unless no body is using it. How do we do that? Implementing a reference counting mechanism in our smart pointer class will solve this problem.
*/