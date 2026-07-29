// linkedlist.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>



using namespace std;
class node
{
public:
    int data;
    node* next;

public:
    node()
    {
        data = 0;
        next = nullptr;

    }
    node(int data1)
    {
        this->data = data1;
        this->next = nullptr;
    }
};
class llist
{
public:
    node* hdr;

public:
    llist() { hdr = nullptr; }
    void insert(int a)
    {
        node* temp = new node(a);
        
        

        if (hdr == nullptr)
        {
            //temp->next = *hdr;
            (hdr) = temp;
        }
        else
        {
            node* temp1   = hdr;
            while ((temp1)->next != nullptr)
                (temp1) = (temp1)->next;
            (temp1)->next = temp;
            //*hdr = (*node1);

        }
        
    }
    void insertbeg(int data1)
    {
        node* temp1 =  new node(data1);
        temp1->next = hdr;
        hdr = temp1;


    }

    void deletespenod(int data1)
    {
        node* temp = hdr;
        node* temp1 = hdr->next;
        while (temp->data != data1)
        {
            
            temp = temp->next;
            temp1 = temp->next;
            
            if (temp->next == nullptr)
            {
                std::cout << "data was not found t delete node" << std::endl;
                return;
            }

        }
        std::cout << "node data:"<<temp->data << "deleted" << std::endl;
        temp->next = temp1->next;
        temp->data = temp1->data;
        delete temp1;

    }
    void display()
    {
        node* tmp = hdr;
        while (tmp)
        {
            std::cout<<(tmp->data)<< "-->";
            tmp = tmp->next;
        }
        std::cout << "---------------------------------------------" << std::endl;
    }
    void reversll()
    {
        node* p = hdr;
        node* prev = nullptr;
        node* nxt = nullptr;
       while (p)
       {                                 //2-->4--->6-->8
            nxt = p->next;                           //
            p->next = prev; // 2->null 4->2->null 6->4->2
            prev = p;       //2 4 6
            //4
            
            p = nxt;//6
            //p = q;
            
        }
        
        hdr = prev;

        std::cout << "reverse ll ended" << std::endl;
    }

    /*rever ll recursive method*/
    /*
     node* reverllrec(node** temp1)

    {
        
        if (*temp1 == nullptr)
        {
            std::cout << "llist empty";
            return nullptr;
        }
            
        if ((*temp1)->next == nullptr)
        {
                hdr = *temp1;
                return *temp1;
        }
            //node* node1 = new node();
            node* node1 = reverllrec(&(*temp1)->next);
            node1->next = *temp1;
            (*temp1)->next = nullptr;
           // hdr = temp1;
            return hdr;
      
      
    }
    */
    node* gethdr()
    {
        return hdr;
    }

    bool findloopll()
    {
        node* sllstp = hdr;
        node* fllstp = hdr;
        node* sll;
        hdr->next->next->next->next->next = hdr; //testing purpose adding loop
        while (sllstp && fllstp && fllstp->next)
        {
            sll = sllstp;
            sllstp = sllstp->next;
            fllstp = fllstp->next->next;
            if (sllstp == fllstp)
            {
                std::cout << "loop found at:" << fllstp->data << std::endl;
                sll->next = nullptr;  //removing loop
                display();
                return true;

            }
            
        }
        std::cout << "loop not fou`qnd" << std::endl;
        return false;
    }
};

int main()
{
    llist* node = new llist();
    node->insert(2); //insert at end
    node->insert(34);
    node->insert(4);
    node->insert(56);
    node->insertbeg(31); ///inser at begining
    node->insert(45);
    node->display();
    node->deletespenod(4); //delete specific node
    node->display();
    node->reversll();
    node->display();
   // llist* temp = new llist();


    
    //node->gethdr();

    //node->reverllrec(&(node->gethdr()));
    node->display();
    node->findloopll();
    node->display();
    std::cout << "Hello World!\n";
}
