// vector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
#include <iostream>
#include <vector>
#include<algorithm>

int main()
{
    std::vector<int>v1{ 1,4,0,0,5,6,34,53,21,21,35,66,32 };
    v1.erase(std::remove(v1.begin(), v1.end(), 0), v1.end());
    v1.erase(unique(v1.begin(), v1.end()), v1.end()); // remove duplicates
    v1.shrink_to_fit();
    std::sort(v1.begin(), v1.end(), [](int a, int b)->bool { return a > b; });//sort
    for (auto i : v1)
    {
        std::cout << i << std::endl;
    }

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
*/
// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void Add(vector<int>*v1, int value) 
{
    v1->push_back(value);
    // TODO: implement
}

bool Delete(vector<int>v, int value) {
    vector<int>*v1 = &v;
    auto it = find(v1->begin(), v1->end(), value);
    if (it != v1->end())
    {
        v1->erase(it);
        // TODO: implement
        v = *v1;
        return true;
    }
    return false;
}

int GetMedian(vector<int>v1)
{
    // TODO: implement

    std::sort(v1.begin(), v1.end());
    int n = v1.size();

    if ((n == 0))
        throw std::runtime_error(" container empty");;

    if ((n == 1))
        return v1[n];

    if (n % 2 != 0)
        return v1[(n + 1) / 2];
    else
        //return  double(v1[n-1]/2+v1[n]/2)/2.0;

          //return  (v1[(n/2-1)] + v1[n/2] ) /2.0; 
        // return (double)(v1[(n - 1) /2]+ v1[n/2] )/ 2.0; 
        return  v1[(n / 2 - 1)];

}
void disply(vector<int>v1)
{
    for (auto ptr : v1)
        std::cout << ptr << " ";
    std::cout << std::endl;
}

int main() {
    // Write C++ code here
    std::vector<int>v;
    Add(&v, 3);
    Add(&v, 4);
    Add(&v, 1);
    Add(&v, 5);
    std::cout << "Try programiz.pro";
    disply(v);
    Delete(v, 1);
    disply(v);
    return 0;
}