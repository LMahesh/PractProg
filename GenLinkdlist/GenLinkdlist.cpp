/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>


template<typename T>
class node
{
public:
    T data;
    node* next;

    node()
    {
        next = nullptr;


    }
public:
    node(T dat)
    {
        data = dat;
        next = nullptr;


    }


};

template<typename T>
class llist
{
public:
    node<T>* hdr;

    llist()
    {
        hdr = nullptr;
    }
    void addatbeg(int dat)
    {

        node<T>* temp = new node<T>(dat);
        if (hdr == nullptr)
        {

            hdr = temp;
        }

        else
        {
            node<T>* temp1 = hdr;
            while (temp1->next)
                temp1 = temp1->next;

            temp1->next = temp;

        }

    }

    void printdata()
    {
        node<T>* temp1 = hdr;
        while (temp1)
        {

            std::cout << temp1->data << "------>";
            temp1 = temp1->next;
        }

    }
    void reversllst()
    {

        node<T>* prev = nullptr;
        node<T>* next;
        node<T>* q = hdr;

        while (q)
        {

            next = q->next;
            q->next = prev;
            prev = q;

            q = next;

        }

        hdr = prev;
    }


    //copy constructor

    llist(const llist& llst1)
    {
        while (llst1)
        {

            this->addatbeg(llst1->data);
            llst1 = llst1->next;
        }


    }

};


int main()
{
    std::cout << "Hello World" << std::endl;

    llist<int>* llst = new llist<int>();
    llst->addatbeg(34);
    llst->addatbeg(24);
    llst->addatbeg(54);
    llst->addatbeg(64);
    llst->addatbeg(14);
    llst->addatbeg(114);

    // llist<int>* llst1 = new llist<int>(llst);

    llst->printdata();

    llst->reversllst();
    std::cout << "------------------------------" << std::endl;
    llst->printdata();
    return 0;
}