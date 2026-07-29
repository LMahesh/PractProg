// unordermap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
#include<map>
#include<string>
// https://www.geeksforgeeks.org/return-maximum-occurring-character-in-the-input-string/?ref=ml_lbp
void findrepeatedchar(const char* str)
{
    int len = strlen(str);
    int cnt = 0;
    char ch = '\0';
    std::unordered_map<char, int>unmp;
    for (int i = 0; i < len; i++)
    {
        unmp[str[i]]++;
        if (cnt < unmp[str[i]])
        {
            cnt = unmp[str[i]];
            ch = str[i];
        }
    }
    std::cout << "char :" << ch <<"   " << "occurrs" << cnt << "times" << std::endl;

    for (auto& ai : unmp)
        std::cout << ai.first<<" :" << ai.second << std::endl;
}

int main()
{
    findrepeatedchar("Geeks for Geeks");
    std::cout << "Hello World!\n";

    std::unordered_map<std::string, double> umap = {  //inserting element directly in map 
      {"One", 1},
      {"Two", 2},
      {"Three", 3},
        {"Three",4},
        {"Four",2},};
    //std::unordered_map<std::string, int>::iterator it;
   // for (it = umap.begin();it != umap.end();it++)

    std::cout << "----------------unorderMap------------------------------------000000" << std::endl;
    for(auto it:umap)
    {
        std::cout << it.first <<" " << it.second << std::endl;
    }

    std::cout << "----------------Map------------------------------------000000" << std::endl;


    std::map<std::string, double> map1 = {  //inserting element directly in map 
      {"One", 1},
      {"Two", 2},
      {"Three", 3},
        {"Three",4},
        {"Four",2}, };
    //std::unordered_map<std::string, int>::iterator it;
   // for (it = umap.begin();it != umap.end();it++)
    for (auto it : map1)
    {
        std::cout << it.first << " " << it.second << std::endl;
    }
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
