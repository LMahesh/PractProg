// Online C++ compiler to run C++ program online
#include <iostream>

class Singleton
{

public:
    static Singleton* sptr;
    static Singleton* createIns()
    {
        if (sptr == NULL)
            sptr = new Singleton();
        return sptr;

    }
    void Display()
    {
        std::cout << "Iam singleton" << std::endl;

    }
private:
    Singleton() {}
    Singleton(Singleton& t) {}
};
Singleton* Singleton::sptr = NULL;
int main()
{
    // Write C++ code here
    std::cout << "Try programiz.pro";
    Singleton* sobj = Singleton::createIns();
    Singleton& sobj1 = *Singleton::createIns();
    Singleton* sobj2 = sobj->createIns();
    sobj1.Display();

    return 1;
}