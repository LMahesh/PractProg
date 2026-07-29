// stringpermutation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <
iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

void next()
{
    int n = 2; //permutation combinatio length
    std::vector<std::string>v1 = { "a", "b", "c", "d", "e" };
    std::set<std::vector<std::string>>result;
    do {
        result.emplace(v1.begin(),v1.begin()+n);
    } while(std::next_permutation(v1.begin(),v1.end()));

    for (auto& it : result)
    {
        for(auto& it1:it)
        std::cout<< it1;
        std::cout << endl;
    }

}

int main()
{
    std::cout << "Hello World!\n";
    next();
    return 1;
}