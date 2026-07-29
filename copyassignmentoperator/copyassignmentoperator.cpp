// Online C++ compiler to run C++ program online
#include <iostream>
#include <cstring>
using namespace std;
class Test
{
public:
    Test() { bint = 0; str = nullptr; std::cout << "constructor" << std::endl; }
  
    Test(int a,const char* b)
    {
        bint = a;
        int length = strlen(b);
        str = new char[length];
        str = b;
        
    }
    Test& operator=(Test& T1)
    {
        std::cout << "Assignment Operator" << std::endl;
        std::cout << T1.bint << T1.str << std::endl;
        bint = T1.bint;
        int length = strlen(T1.str);
        this->str = new char[length];
        this->str = T1.str;
        return *this;
    }
    Test(Test& T1)
    {
        std::cout << "copy constructor" << std::endl;
        this->bint = T1.bint;
        int length = strlen(T1.str);
        std::cout << "length is:" <<length<< std::endl;
        this->str = new char[length];
        str=T1.str;
    }

    /*
    // *** Move Constructor (Rule of Five) ***
    MyString(MyString&& other) noexcept 
        : data(other.data), length(other.length) // Steal the resource
    {
        other.data = nullptr;  // Release the resource from the source
        other.length = 0;
    }

    // *** Move Assignment Operator (Rule of Five) ***
    MyString& operator=(MyString&& other) noexcept {
        if (this != &other) {
            delete[] data; // Free existing resources of the current object
            
            // Transfer ownership from source to current object
            data = other.data;
            length = other.length;

            // Release the data pointer from the source object so its destructor doesn't free the memory
            other.data = nullptr;
            other.length = 0;
        }
        return *this;
    }*/
    
public:
    int bint;
    const char* str;
};
int main() 
{
    // Write C++ code here
    int a = 24;
    const char* ptr = "string123";
    Test t1(2,"string123");
    Test t2, t3;
    t3 = t2 = t1;
    Test t4 = t1;
    std::cout << "_____________" << std::endl;
    std::cout << t2.bint <<" "<< t3.bint << " "<<t4.bint<<std::endl;
    std::cout << t2.str << " "<<t3.str<<" "<<t4.str << std::endl;
    std::cout << "Try programiz.pro";
    t1.str = "Mahesh";
    std::cout << t1.str << " " << t3.str << " " << t4.str << std::endl;
    return 0;
}