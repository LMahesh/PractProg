// Online C++ compiler to run C++ program online
#include <iostream>
#include <memory>
class node;
class test
{
public:
    //std::shared_ptr<node>node_ptr;
    std::weak_ptr<node>node_ptr;
    ~test()
    {

        std::cout << "test destructor" << std::endl;
    }

};


class node
{

public:
    std::shared_ptr<test>test_ptr;
    ~node()
    {
        std::cout << "node destructor" << std::endl;    
    }
};
int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro";
    auto tst = std::make_shared<test>();
    auto nde = std::make_shared<node>();
    tst->node_ptr = nde;
    nde->test_ptr = tst;
    return 0;
}