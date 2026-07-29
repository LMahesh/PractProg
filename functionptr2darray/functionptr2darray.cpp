// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#define rows 3
#define colmns 3

int sum(int a, int b)
{
    return a + b;
}
int sub(int a, int b)
{
    return a - b;
}

int main() {


    int (*fptr[2])(int, int) = { &sum,&sub };
    std::cout << fptr[1](2, 3) << std::endl;
    // Write C++ code here
    std::cout << "Try programiz.pro";

    int** ptr = new int* [rows];

    for (int i = 0; i < rows; i++)
    {
        ptr[i] = new int[colmns];

    }
    for (int i = 0; i < rows; i++)
    {
        delete[] ptr[i];

    }

    delete[] ptr;

    return 0;
}