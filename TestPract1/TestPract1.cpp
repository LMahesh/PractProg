/*
#include <iostream>

template <typename T>
class unique_ptr {
public:
    // Constructor
    explicit unique_ptr(T* ptr = nullptr) : ptr_(ptr) {}

    // Destructor
    ~unique_ptr() {
        delete ptr_;
    }

    // Copy constructor and assignment operator deleted
    unique_ptr(const unique_ptr&) = delete;
    unique_ptr& operator=(const unique_ptr&) = delete;

    // Move constructor and assignment operator
    unique_ptr(unique_ptr&& other) noexcept : ptr_(other.ptr_) {
        other.ptr_ = nullptr;
        std::cout << "move constructor" << std::endl;
    }

    unique_ptr& operator=(unique_ptr&& other) noexcept {
        if (this != &other) {
            delete ptr_;
            ptr_ = other.ptr_;
            other.ptr_ = nullptr;
        }
        return *this;
    }

    // Member functions
    T* get() const noexcept {
        return ptr_;
    }

    T* release() noexcept {
        T* temp = ptr_;
        ptr_ = nullptr;
        return temp;
    }

    void reset(T* ptr = nullptr) noexcept {
        delete ptr_;
        ptr_ = ptr;
    }

    T& operator*() const noexcept {
        return *ptr_;
    }

    T* operator->() const noexcept {
        return ptr_;
    }

    explicit operator bool() const noexcept {
        return ptr_ != nullptr;
    }

private:
    T* ptr_;
};

class tst {

public:
    tst()
    {
        std::cout << "tst constructor" << std::endl;
    }

    void func() { std::cout << "member function" << std::endl; }

};

int main()
{

    std::cout << "Hello World";
    unique_ptr<tst>cptr(new tst());
    cptr->func();
    unique_ptr<tst>cptr1 = std::move(cptr);


    std::string str = "Mahesh123Lagisetty123Msc";

    for (std::string::size_type i = str.find("123"); i != std::string::npos; i = str.find("123"))
    {
        str.erase(i, 3);
    }
    std::cout << "-----------------------------------" << std::endl;
    std::cout << str << std::endl;



    //------------------------------------------------------
        int arr[] = { -2, 6, -3, -10, 0, 2 };

    int size = sizeof(arr) / sizeof(arr[0]);
    int maxprod = 0;
    int RighttoLeft = 1;
    int LefttoRight = 1;
    for (int i = 0; i < size; i++)
    {
        if (RighttoLeft == 0)
            RighttoLeft = 1;
        if (LefttoRight == 0)
            LefttoRight = 1;
        LefttoRight = LefttoRight * arr[i];
        int j = size - i - 1;
        RighttoLeft = RighttoLeft * arr[j];
        // maxprod = max({RighttoLeft,LefttoRight,maxprod});
        maxprod = std::max({ LefttoRight, RighttoLeft, maxprod });

        std::cout << "Max prod subarray" << maxprod << std::endl;
    }

    return 0;
}

************/

/*************

// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <cstring>


using namespace std;
void printpattern(int k)
{
    std::string str;
    if (k == 1)
    {
        str = "1";
        std::cout << str << std::endl;
    }
    if (k == 2)
    {
        str = "11";
        std::cout << str << std::endl;
    }
    str = "11";


    for (int i = 3; i <=k; i++)
    {
        int cnt = 1;
        str = str + '$';
        string tmp = "";
        int len = str.size();
        for (int n = 1; n <len; n++)
        {
            if (str[n - 1] != str[n])


            {
                tmp += cnt + '0';
                tmp += str[n - 1];
                cnt = 1;
            }
            else
            {
                cnt++;
            }
        }
        str = tmp;
    }
    std::cout << str << std::endl;

}

class Test
{
public:
    int a;
public:
    Test(int b)
    {
        a = b;
    }
    Test()
    {
        int a = 0;

    }
    void display()
    {
        std::cout << "value is: " << a << std::endl;
    }

};


class A
{
public:

    virtual void display()
    {
        std::cout << "Aclass Memeber fn()" << std::endl;
    }
};
class B: public A
{
public:

    void display()
    {
        std::cout << "Bclass Memeber fn()" << std::endl;
    }
};
class c:public A
{
public:

    void display()
    {
        std::cout << "C class Memeber fn()" << std::endl;
    }
};
int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro";


    A* Aptr = new B();

    

    Test* tptr = new Test(5);
    std::shared_ptr<Test>spt(new Test(6));
    Test* a = spt.get();
    spt->display();
    std::shared_ptr<Test>spt1 = move(spt);
    //std::shared_ptr<Test>spt1 = std::make_shared<Test>(Test(5));

    std::shared_ptr<Test>spt4 = std::make_shared<Test>(Test(65));
    Test* a1 = spt4.get();
    std::cout << "---------------" << std::endl;
    spt4->display();

    std::unique_ptr<Test>uptr(new Test());
    std::unique_ptr<Test>uptr1 = std::make_unique<Test>();

    std::weak_ptr<Test>wptr(spt1);//does not allow spt
    if (!wptr.expired()) //not enter for spt
    {
        std::cout << "aceesing using weak ptr:" << std::endl;
        std::cout << (*wptr.lock()).a<< std::endl;
    }
    wptr.reset();
    //spt->display();
    //
    //int s;
    //std::cout << "Enter number:" << std::endl;
   // std::cin >> s;
    //printpattern(s);
    //


    const char* str1 = "Lag Mahesh Lagisetty Mah LagMaheshLag";
    string str = str1;
    std::cout <<"---before erase"<< str <<"----------" << std::endl;
    string substr = "Lag";
    for (string::size_type i = str.find(substr); i != string::npos; i = str.find(substr))
        str.erase(i, substr.length());
    std::cout << "---after erase substr" << str << "----------" << std::endl;



    return 0;
}

*/


// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>

using namespace std;

int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro";

    std::string str = "35235";
    std::cout << "Enter the string for largest odd" << std::endl;
    std::cin >> str;
    int k;
    int len = str.length();
    //std::cout <<"len=: "<< len << std::endl;
   // for(int k = 0;k>)
    for(int i = len; i >= 0; i--)
    {
        if ((str[i] - '0')% 2 != 0)
        {
            k = i;
            std::cout << "index: " << k;

            break;
        }

        
    }
    for (int l = 0; l <= k; l++)
    {
         std::cout<<str[l];    
    }

    return 0;
}