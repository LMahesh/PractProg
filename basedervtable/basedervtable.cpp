// Online C++ compiler to run C++ program online
#include <iostream>


class base
{
public:

    void virtual func1() {};
    void func2() {};
    void  virtual func3() { std::cout << "Iam base vfunc3"; };
};
// Vtable creates for Base and derive
//Base class Table contains  Func1,Func3
// Derived class Table contains Func1,Func3,Func4
class Der :public base
{
public:
    void func1()override {};
    void virtual func4() { std::cout << "derived f4"; };
    void display() {}

};


int main() {
    // Write C++ code here
    base* bptr = new Der();
    bptr = dynamic_cast<base*>(bptr);

    Der* dptr = new Der();
    bptr->func3();
    
    dptr->func4();
    // Der* der = new base();
    std::cout << "Try programiz.pro";

    return 0;
}