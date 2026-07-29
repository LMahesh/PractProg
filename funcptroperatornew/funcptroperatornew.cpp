// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
class Test
{
public:
    int dat;
    std::string name;
    void* operator new(size_t t)
    {
        std::cout << " overload new operator func" << std::endl;
        std::cout << "size is :" << t << std::endl;

        //Test* t = new Test();
        void* ptr = ::operator new(t);
        return ptr;
    }
    Test(int a, std::string ptr)
    {
        dat = a;
        name = ptr;

    }
    Test()
    {

    }
    void Test1()
    {
        std::cout << "class Member function" << std::endl;
    }
};

int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro" << std::endl;

    Test* tst1 = new Test(2, "Mahesh");
    tst1->Test1();
    Test tst;
    void (Test:: * funptr)() = &Test::Test1;
    (tst1->*funptr)();
    std::cout << tst.dat << std::endl;
    return 0;
}