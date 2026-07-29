//The Curiously Recurring Template Pattern (CRTP) is a powerful C++ design idiom
//  where a class derives from a base class template, 
// using the derived class itself as the template argument.
//used to achieve static polymorphism (compile-time polymorphism).
//  This eliminates the runtime overhead of virtual function tables (vtable) and pointers (vptr), 
// enabling the compiler to inline function calls for maximum execution speed.

#include <iostream>

template<typename derived>
class marketParser
{
public:
	void publishmarketdata(const char* dat)
	{
		static_cast<derived*>(this)->newyorkparserdat(dat);
     }
	
};
class newyorkmktParser :public marketParser<newyorkmktParser>
{
public:
	void newyorkparserdat(const char* data)
	{
		std::cout << "derived newyork pars data:" << data << std::endl;
	}
};

int main()
{
	std::cout << "Hello World!\n" << std::endl;

	newyorkmktParser np;
	const char* dat = "market data";
	np.publishmarketdata(dat);
	return 0;
}
