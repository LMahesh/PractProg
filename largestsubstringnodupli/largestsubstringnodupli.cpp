// largestsubstringnodupli.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

void largestsubstr(string str)
{
    
    int l = 0;
    int r = 0;
    int maxl = 0;
    int maxr = 0;
    int maxstr = 0;
    unordered_set<char> visited;
    int n = str.size();
    while (r < n)
    {
        if (visited.find(str[r]) == visited.end())
        {
            visited.insert(str[r]);

            if (r - l + 1 > maxstr)
            {
                maxstr = r - l + 1;
                maxl = l;
                maxr = r;
                std::cout << "maxstr:" << maxstr << std::endl;
            }
            r++;
            std::cout << "r" << r << std::endl;
        }

        else {

            visited.erase(str[l]);
            l++;
            std::cout <<"l:"<< l << std::endl;
        }
    }


    std::cout << "maxl"<<maxl << "maxr" << maxr << std::endl;
    for (int i = maxl; i <= maxr; i++)
    {
    
    std::cout << str[i];
        }
        std::cout << "length: " << maxr-maxl+1;


        




    }





int main()
{
    std::cout << "Hello World!\n";

    std::string str = "abcbccaabcd";

    largestsubstr(str);

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
