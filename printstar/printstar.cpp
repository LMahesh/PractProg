#include <iostream>
using namespace std;


void printst(int n)
{
    //int k = 0;
    for (int i = 0, k = 0; i < n; i++)
    {
        for (int j = 0; j < n-i; j++)
        {

            std::cout << " ";

        }
        /*while (k < 2 * i - 1)
        {
            std::cout << "* ";
            k++;
        }*/
        for(int k =0;k<2*i-1;k++)
            std::cout << "* ";
        std::cout << std::endl;
    }
}
int main() {
    int N;
    std::cout << "enter the value" << std::endl;
    printst(15);

    // std::cout << "Hello world" << std::endl;
    return 0;
}
