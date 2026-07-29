// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
/*
class RC
{
    int count;
public:
    RC() :count(0) {}
    void addrefcnt() { count = count + 1; }
    int release() { return --count; }
    int getcnt() { return count; }
};
template<typename T>class my_sharedptr
{

private:
    //RC* ref_count;
    T* ptr;
public:
    RC* ref_count;
    my_sharedptr() :ptr(NULL), ref_count(NULL)
    {
        std::cout << "constructor" << std::endl;
        ref_count = new RC();
        ref_count->addrefcnt();
        ptr = NULL;

    }

    my_sharedptr(T* ptr1 = NULL)
    {
        std::cout << "constructor1" << std::endl;
        ptr = ptr1;
        std::cout << "1" << std::endl;
        // if(ref_count == NULL)
        {
            std::cout << "2" << std::endl;
            ref_count = new RC();
        }
        ref_count->addrefcnt();
    }
    
    my_sharedptr(const my_sharedptr<T>& my_sobj)
    {
        std::cout << "copy construct" << std::endl;
        ptr = my_sobj.ptr;
        ref_count = my_sobj.ref_count;
        ref_count->addrefcnt();

    }
    
    my_sharedptr(my_sharedptr<T>&& my_sobj)noexcept:ptr(nullptr),ref_count(nullptr)
    {
        std::cout << "mov construct" << std::endl;
        ptr = my_sobj.ptr;
        ref_count = my_sobj.ref_count;
        ref_count->addrefcnt();

    }
    my_sharedptr& operator=(const my_sharedptr<T>& my_sobj)
    {

        std::cout << "opertot =" << std::endl;
        if (this->ptr != my_sobj.ptr)
        {

            if (this->ptr && this->ref_count)
            {
                ref_count->release();
                if (ref_count->count == 0)
                {
                    delete this.ptr;
                }
            }

        }

        this->ptr = my_sobj.ptr;
        this->ref_count = my_sobj.ref_count;
        ref_count->addrefcnt();
        return *this;

    }

    T& operator*()
    {
        return *ptr;
    }

    T* operator->()
    {
        return ptr;
    }

    friend ostream& operator<<(ostream& os, my_sharedptr<T> sobj)
    {
        os << "Address pointed:" << sobj.ptr << "   " << "count:" << sobj.ref_count->getcnt() << std::endl;

        return os;
    }

};
int main()
{
    // Write C++ code here
    std::cout << "Try programiz.pro" << std::endl;;
    my_sharedptr<int>s_ptr(new int(10)); //copycnstr got invoking
    std::cout << "s_ptr:" <<s_ptr << std::endl;//copycnstr got invoking
                                                                                //passing object to friend ostrem<<)
    
    //std::cout << "s_ptr:" <</*s_ptr <<*/ 
   
    
    
    /*s_ptr.ref_count->getcnt() << std::endl;
  
    
        my_sharedptr<int>s_ptr1 = s_ptr;
    std::cout << "s_ptr:" << s_ptr1 << std::endl;
    //std::cout << "s_ptr1:" << s_ptr1.ref_count->getcnt() << std::endl;
    my_sharedptr<int>s_ptr2 = (s_ptr);
    std::cout << "s_ptr2:" << s_ptr2.ref_count->getcnt() << std::endl;
    return 0;
}*/


////////////////////////////////////////////////////////////////////////////////



template<typename T>
class myshared_ptr
{
private:
    T* _ptr;
    int* _cnt;
   void release()
    {
       if (_cnt && --(*_cnt) == 0)
       {
           delete _ptr;
           delete _cnt;
       }

       _ptr = nullptr;
       _cnt = nullptr;

    }

public:
    myshared_ptr(T* ptr = nullptr):_ptr(ptr),_cnt(nullptr)
    {
        if (ptr != nullptr)
            _cnt = new int(1);
        _ptr = ptr;

    }

    myshared_ptr(const myshared_ptr& obj)
    {
        //release();
        _ptr = obj._ptr;
        _cnt = obj._cnt;
        if (_cnt != nullptr)

            (*_cnt)++;
    }
    myshared_ptr& operator=(const myshared_ptr& obj)
    {
        if (this != &obj)
        {
            release();
            _ptr = obj._ptr;
            _cnt = obj._cnt;
            if (_cnt != nullptr)

                (*_cnt)++;
        }
        return *this;
    }

    T& operator*() const
    {
        return *_ptr;
    }

    T* operator->() const
    {
        return _ptr;
    }
    ~myshared_ptr()
    {
        release();
    }
    int use_count() const
    {
        return _cnt ? *_cnt : 0;
    }
    void reset(T* ptr = nullptr){
        release();

        _ptr = ptr;

        if (ptr)
            _cnt = new int(1);
        else
            _cnt = nullptr;
    }
};



int main()
{

    return 0;
}