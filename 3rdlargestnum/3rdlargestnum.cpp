/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

void get3rdlargest(std::vector<int>& v)
{
    std::cout << "------------get3rdlargest number method---------------" << std::endl;
    int first = INT_MIN;
    int second = INT_MIN;
    int third = INT_MIN;
    for (auto& num : v)
    {

        if (num == first || num == second || num == third)
            continue;

        if (num > first)
        {
            third = second;
            second = first;
            first = num;

        }
        else if (num > second)
        {
            third = second;
            second = num;
        }
        else if (num > third)
        {
            third = num;
        }
    }

    std::cout << "greater 3rdnum:" << third;

    std::cout << "----------------------------------------------" << std::endl;
}
int main()
{
    std::cout << "Hello World" << std::endl;
    std::vector<int>v1{ 23,45,12,34,39,67,89 };

    get3rdlargest(v1);



    std::sort(v1.begin(), v1.end());

    for (auto& it : v1)
    {
        std::cout << it << " ";
    }
    std::cout << "3rd largest number: " << v1[v1.size() - 3];





    std::sort(v1.begin(), v1.end(), std::greater<int>());

    for (auto& it : v1)
    {
        std::cout << it << " ";
    }
    std::cout << "3rd largest number: " << v1[2];

    return 0;
}