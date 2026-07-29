#include "container.h"
#include <stdexcept>
#include <iostream>
#include <vector>
#include <algorithm>
void Container::Add(int value) {
    v1.push_back(value);
    // TODO: implement
}

bool Container::Delete(int value) {



    auto it = find(v1.begin(), v1.end(), value);
    if (it != v1.end())
    {
        v1.erase(it);
        // TODO: implement
        return true;
    }
    return false;
}

int Container::GetMedian()
{
    // TODO: implement

    std::sort(v1.begin(), v1.end());
    int n = v1.size();

    if ((n == 0))
        throw std::runtime_error(" container empty");;

    if ((n == 1))
        return v1[0];


    if (n % 2 != 0)
        return v1[((n + 1) / 2)-1];
    else
        //return  double(v1[n-1]/2+v1[n]/2)/2.0;

          //return  (v1[(n/2-1)] + v1[n/2] ) /2.0; 
        // return (double)(v1[(n - 1) /2]+ v1[n/2] )/ 2.0; 
        return  v1[(n / 2 - 1)];

    //  catch (std::exception &e) 
     //{
       // 	std::cout<<"Caught exception: "<<e.what()<<"\n";
       //}

}

void Container::display()
{
    for (auto ptr : v1)
        std::cout << ptr<<" ";
    std::cout << std::endl;
    std::cout << "----------------------------------------------------------" << std::endl;

}
void main()
{
    Container container_;
    container_.Add(5);
    container_.Add(3);
    container_.Add(5);
    container_.display();
    container_.Delete(5);
    container_.display();
    container_.Delete(5);
    container_.display();
    int a = container_.GetMedian();
    std::cout << "getmedian" << a << std::endl;
    container_.Delete(3);
    for (int i = 10; i >= 1; --i) {
        container_.Add(i);
    }
    //container_.GetMedian();
    a = container_.GetMedian();
    std::cout << "getmedian" << a << std::endl;
    for (int i = 4; i <= 6; ++i) {
        container_.Delete(i);
    }
    container_.display();
    //container_.GetMedian();
    a = container_.GetMedian();
    std::cout << "getmedian" << a << std::endl;
    container_.Delete(1);
    container_.Delete(2); container_.Delete(3); container_.Delete(7); container_.Delete(8); container_.Delete(9);
    container_.Delete(10);
    /// <summary>
    /// //Test 4
    /// </summary>
    container_.Add(1);
    container_.Add(2);
    container_.Add(5);
    container_.Add(4);
    std::cout << "getmedian" << container_.GetMedian() << std::endl;
    container_.Delete(1);
    container_.display();
    std::cout << "getmedian:" << container_.GetMedian() << std::endl;
}