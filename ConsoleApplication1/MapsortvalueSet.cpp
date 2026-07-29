// Online C++ compiler to run C++ program online
#include <iostream>

#include <map>
#include <set>

using namespace std;

struct comp {
    template <typename T>

    // Comparator function

    bool operator()(const T& l, const T& r) const
    {
        if (l.second != r.second) {
            return l.second > r.second;
        }
        return l.first > r.first;
    }
};

void sort(map<std::string, int>& m1)
{
    std::set<pair<string, int>, comp> S(m1.begin(), m1.end());

    
    ////////////////////multimap logic///
    std::multimap<int,string>mm1;
    for (auto& i : m1)
    {
        mm1.insert({ i.second, i.first });
    }
    /////////////////////////////////////
    for (const auto& itr : S)
    {
        
            std::cout << itr.first << ":" << itr.second << std::endl;
        
    }
    std:cout << "________________end of set opertor print" << std::endl;
    for (const auto& itr : mm1)
    {
        std::cout << itr.second << ":" << itr.first << std::endl;
    }
    
}


int main()

{
    std::map<string, int>map1;
    map1.insert(pair<string, int>("one", 1));
    map1["Four"] = 4;
    map1["five"] = 5;
    map1["Five"] = 5;
    map1["Zero"] = 0;

    // Write C++ code here
    std::cout << "Hello world!" << std::endl;;

    for (const auto& itr : map1)
    {
        std::cout << itr.first << ":" << itr.second << std::endl;
    }
    //set<pair<int,string>, comp>s(map1.begin(),map1.end());

    std::cout << "-------------------------------" << std::endl;

    sort(map1);

    return 0;
}