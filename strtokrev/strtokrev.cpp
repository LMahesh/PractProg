// strtokrev.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <stack>


using namespace std;

int main()
{
    std::cout << "Hello World!\n";
    stack<string>stack1;
    string str = "My name is Mahesh";
    string str1 = "";
    stringstream sstr(str);
    while (getline(sstr, str1,' '))

    {
        std::cout << str1 << std::endl;
        stack1.push(str1);
    }

    while (!stack1.empty())
    {
        string str1 = stack1.top();
        stack1.pop();
        std::cout << str1 << " ";
    }
    std::cout<<std::endl;
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
