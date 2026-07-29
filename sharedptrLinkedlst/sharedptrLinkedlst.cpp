// sharedptrLinkedlst.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>

class node
{
public:
    int data;
    std::shared_ptr<node>next;
    node()
    {
        data = NULL;
        std::shared_ptr<node>next(nullptr);
    }
    node(int dat)
    {
        data = dat;
        std::shared_ptr<node>next(nullptr);
    }
};

class llist
{
public:
    std::shared_ptr<node>hdr;
    llist()
    {
        hdr = nullptr;
    }
    void pushdat(int a)
    {
        std::shared_ptr<node>temp = std::shared_ptr<node> (new node(a));
        //std::shared_ptr<node>temp = std::make_shared<node>(a);
        if (hdr == nullptr)
        {
            hdr = temp;
        }
        else
        {
            std::shared_ptr<node>cur = hdr;
            while (cur->next != nullptr)
            {
                cur = cur->next;
            }
             cur->next = temp;

        }


    }
    void printdata()
    {
        std::shared_ptr<node>temp = hdr;
        while (temp)
        {
            std::cout << temp->data << " ";

            temp = temp->next;
        }
    }

    void deldata(int a)
    {
        if (hdr->data == a)
            hdr = hdr->next;
        else
        {
            std::shared_ptr<node>cur = hdr;
            while (cur->next && cur->next->data != a)
            {
                cur = cur->next;
            }
            if (cur->next && cur->next->data == a)
            {
                cur->next = cur->next->next;
            }
        }
    }
};

int main()
{
    llist ll;
    ll.pushdat(18);
    ll.pushdat(232);
    ll.pushdat(123);
    ll.pushdat(53);
    ll.pushdat(43);

    ll.printdata();
    ll.deldata(123);
    std::cout << "after remove data 123" << std::endl;
    ll.printdata();
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
