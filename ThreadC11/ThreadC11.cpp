// ThreadC11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// C++ program to demonstrate
// multithreading using three
// different callables.

/*
#include <iostream>
#include <thread>
using namespace std;

// A dummy function
void foo(int Z)
{
	for (int i = 0; i < Z; i++) {
		cout << "Thread using function"
			" pointer as callable\n";
	}
}

// A callable object
class thread_obj {
public:
	void operator()(int x)
	{
		for (int i = 0; i < x; i++)
			cout << "Thread using function"
			" object as callable\n";
	}
};

// class definition
class Base {
public:
	// non-static member function
	void foo()
	{
		cout << "Thread using non-static member function "
			"as callable"
			<< endl;
	}
	// static member function
	static void foo1()
	{
		cout << "Thread using static member function as "
			"callable"
			<< endl;
	}
};

// Driver code
int main()
{
	cout << "Threads 1 and 2 and 3 "
		"operating independently"
		<< endl;

	// This thread is launched by using
	// function pointer as callable
	thread th1(foo, 3);

	// This thread is launched by using
	// function object as callable
	thread th2(thread_obj(), 3);

	// Define a Lambda Expression
	auto f = [](int x) {
		for (int i = 0; i < x; i++)
			cout << "Thread using lambda"
			" expression as callable\n";
		};

	// This thread is launched by using
	// lambda expression as callable
	thread th3(f, 3);

	// object of Base Class
	Base b;

	thread th4(&Base::foo, &b);

	thread th5(&Base::foo1);

	// Wait for the threads to finish
	// Wait for thread t1 to finish
	th1.join();

	// Wait for thread t2 to finish
	th2.join();

	// Wait for thread t3 to finish
	th3.join();

	// Wait for thread t4 to finish
	th4.join();

	// Wait for thread t5 to finish
	th5.join();

	return 0;
}
*/

using namespace std;
#include <iostream>
#include <thread>


void fun(int a)
{
	std::cout << "thread function: " << a << std::endl;
}

auto f = [](int a)
	{
		std::cout << "thread lambda exp:" << a << std::endl;
	};

class sample
{
private:
	int a;
public:
	void operator()(int a)
	{
		std::cout << "thread function obj :" << a << std::endl;
	}
};

int main()
{
	sample sobj;
	std::thread th1(fun, 5);
	th1.join();

	std::thread th2(f, 10);
	th2.join();

	std::thread th3(sample(),7);
	th3.join();
	return 1;
}







