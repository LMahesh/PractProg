// smartpointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
#include <iostream>
#include <memory>
class A
{
public:
    A() {};
    A(int a, int b)
    {
        std::cout << a <<":" <<b << std::endl;
    }
    void display()
    {
        std::cout << "member function" << std::endl;
    }

};

int main()
{
    std::shared_ptr<A>Ashptr(new A(2,4));
    std::unique_ptr<A>Auptr(new A(3, 4));

    A Aobj1;
    std::shared_ptr<A>Ashptr1 = std::make_shared<A>(A(4,5));
    std::shared_ptr<A>Ashptr2 =Ashptr;
    Ashptr1->display();
    std::cout << "Hello World!\n";
    std::cout << "count:" << Ashptr.use_count() << std::endl;

    std::weak_ptr<A>wkptr1 = Ashptr;
    Ashptr.reset();
    if (auto lockd_sp = wkptr1.lock())
        std::cout<<" jjjjj"<<(lockd_sp.get()) << std::endl;

    //wkptr1.reset();
    std::cout << Ashptr.get() << " ####" << Ashptr1.get() << std::endl;
    std::cout << Ashptr1.use_count();

}
*/


// Online C++ compiler to run C++ program on
#include <iostream>
#include <memory>

using namespace std;

template<typename T>
class smartpointer
{
    T* ptr;
    public:
    smartpointer()
    { ptr = nullptr;}
    smartpointer(T* ptr1){ptr = ptr1;}


    smartpointer(smartpointer&& smptr)
    {
        std::cout << "Move constructor" << std::endl;
        ptr = smptr.ptr;
        smptr.ptr = nullptr;
    }
    ~smartpointer()
    {
        if(ptr != nullptr)
        delete ptr;
        ptr = nullptr;
        std::cout<<"ptr deleted"<<std::endl;
    }
 T* operator->(){return ptr;}
 T& operator*(){return *ptr;}
    void display()
    {
        std::cout<<ptr<<endl;
    }
};
class A
{
  char* ptr;
  public:
  void display()

  {
      std::cout<<"class memberfunction"<<std::endl;
  }

};
int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro";
    A *a = new A();
    A a2;
smartpointer<A>SpA(new A());
  SpA->display();
  smartpointer<A>SpA1 = std::move(a);
  
  SpA1->display();

    return 0;
}

