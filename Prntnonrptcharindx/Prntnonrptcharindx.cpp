// Prntnonrptcharindx.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;
#define Max_char 26

int main()
{

    string str = "MaheshLagisetty";
    const char*  ptr = "MaheshLagisetty";
    string str1 = ptr;
    std::vector<int>freq(Max_char, 0);

    for (char c : str)
    {
        if (c == ' ')
            continue;
        freq[tolower(c) - 'a']++;
    }

    for (int j = 0; j < str1.length(); j++)
    {
        if (freq[tolower(str1[j]) - 'a'] == 1)
            std::cout << str1[j] <<" :"<<j<< std::endl;
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
