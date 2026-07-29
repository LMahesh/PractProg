// uniqptrsingleton.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class singleton
{

private:

    singleton(){}
public:
    static singleton& gtinstance()
    {
        if (uptrsinstn == nullptr)
        {
            //uptrsinstn = std::make_unique<singleton>(new singleton());
            uptrsinstn.reset(new singleton());
        }
        return *uptrsinstn;
            
    }

    static std::unique_ptr<singleton>uptrsinstn;

    void fun()
    {
        std::cout << "Iam member fn()" << std::endl;
    }

    ~singleton()
    {
        std::cout << "destructor" << std::endl;
     //   if (uptrsinstn != nullptr)
       //     uptrsinstn.reset(nullptr);
    }

    void destfun()
    {
        std::cout << "explicit destructor" << std::endl;
        if (uptrsinstn != nullptr)
                 uptrsinstn.reset(nullptr);
    }
};
std::unique_ptr<singleton> singleton::uptrsinstn = nullptr;

int main()
{
    singleton& sptr = singleton::gtinstance();
    sptr.fun();

    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
