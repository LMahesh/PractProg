// DoubleLLlist.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
class node
{
public:
    node* next;
    node* prev;
    int data;

public:
    node()
    {
        data = 0;
        next = nullptr;
        prev = nullptr;

    }
    node(int dat)
    {
        this->data = dat;
        this->next = nullptr;
        this->prev = nullptr;
    }

};

class doublellist
{
public:
    //int data;
    node* hdr;
    doublellist()
    {
        hdr = nullptr;
       

    }
    void insertdata(int dat1)
    {
        node* temp = new node(dat1);

        if (hdr == nullptr)
            hdr = temp;
        else
        {
            node* temp1 = hdr;

            while (temp1->next != nullptr)
                temp1 = temp1->next;
        
            
            temp1->next = temp;
            temp->prev = temp1->next;
                       
        }
        
    }

    void insertdatapos(int pos,int dat)
    {
        node* temp = hdr;
        node* temp1 = new node(dat);
        node* temp2;
        if (pos == 0) //begining
        {

        }

        while ( temp!=nullptr && pos >0)
        {
            temp = temp->next;
            pos--;
        }
        if (temp != nullptr && temp->next != nullptr)
        {
            temp2 = temp->next;
            temp->next = temp1;
            temp1->prev = temp->next;
            temp1->next = temp2;
            temp2->prev = temp1;
           
            //delete temp2;
        }
    }

    void deldatapos(int pos)
    {
        node* temp = hdr;
        while (temp != nullptr && pos > 0)
        {
            temp = temp->next;
            pos--;
        }

        node* temp1 = temp->next;
        temp->data = temp1->data;
        temp->next = temp->next->next;
       // temp->next->next->prev = temp

        delete temp1;

    }

    void display()
    {
        node* temp1 = hdr;
        while (temp1)
        {
            std::cout << temp1->data << "--->";
            temp1 = temp1->next;
        }
        std::cout << std::endl;


    }

    void sort()
    {
        node* temp1 = hdr;
       

        while (temp1 != nullptr)
        {
            node* temp2 = temp1->next;
            while (temp2 != nullptr)
            {
                if (temp1->data > temp2->data)
                {
                    int tempdata = temp1->data;
                    temp1->data = temp2->data;
                    temp2->data = tempdata;
                }
                temp2 = temp2->next;

            }
            temp1 = temp1->next;
        }
    }

    void reversllist()
    {
        std::cout << "reverse llist :" << std::endl;
        node* p = nullptr;
        node* n = hdr;;
      //  node* n = hdr->next;
        node* q = hdr;
       /* while (n != nullptr)
        {                          //5 --->25---->35
                                   //  <---25<---35
            q->next = p; //5->null
            n->prev = p;// null<-25
            //if (p != nullptr)
             // p->prev = q;
            p = q;      //p =5

            q = n;      // q = 25
          //
         // p->prev = q;//25<--5
            n = n->next; // n =35
        }*/
        while (q != nullptr)
        {                          //5 --->25---->35
            n = q->next;                       //  <---25<---35
            q->next = p; //5->null
            //n->prev = p;// null<-25
            
            p = q;      //p =5

            q = n;      // q = 25
            //
           // p->prev = q;//25<--5
            //n = n->next; // n =35
        }


        hdr = p;
    }
};
int main()
{
    std::cout << "Hello World!\n";
    doublellist* dllist = new doublellist();
    dllist->insertdata(5);
    dllist->insertdata(53);
    dllist->insertdata(35);
    dllist->insertdata(25);
    dllist->insertdata(85);
    dllist->display();
    dllist->sort();
    std::cout << "After sort" << std::endl;
    dllist->display();
    dllist->reversllist();
    dllist->display();
    
    //std::cout << "after insertdata" << std::endl;
    dllist->insertdatapos(2, 100);

    std::cout << "after insertdata pos" << std::endl;
    dllist->display();
    
    dllist->deldatapos(2);

    std::cout << "after deletdata pos" << std::endl;
    dllist->display();


    return 1;
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
