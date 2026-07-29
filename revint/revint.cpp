// revint.cpp8 : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int reverse(int a)
{
    int n = a;
    int c,d=0;
    while (n )
    {
        
        c = n % 10;
        d = d*10 + c;
        n = n / 10;
    }
    return d;
}
int main()
{
    int a;
    std::cout << "enter number toregverse" << std::endl;
    std::cin >> a;
   int  reva = reverse(a);
    std::cout << reva<<"\n";
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
