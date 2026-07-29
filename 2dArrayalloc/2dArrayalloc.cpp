// Online C++ compiler to run C++ program online
#include <iostream>
#define rows 3
#define cols 3

#define my_sizeof(obj) (char*)(&obj+1)-(char*)(&obj)


int main() {

    int arr[10];
    char str[] = "Maheshgggg";
    std::cout << my_sizeof(arr) << std::endl;

    std::cout << my_sizeof(str) << std::endl;

    std::cout << sizeof(str) << std::endl;

    int** ptr = new int* [cols];
    for (int i = 0; i < rows; i++)
    {
        ptr[i] = new int[cols];
    }
    for (int j = 0; j < rows; j++)
    {
        for (int k = 0; k < cols; k++)
        {
            if (k == j)
            {
                ptr[j][k] = 0;
            }
            else
                ptr[j][k] = k + j;
        }
    }
    // Write C++ code here
    for (int j = 0; j < rows; j++)
    {
        for (int k = 0; k < cols; k++)
            std::cout << ptr[j][k] << " ";
        std::cout << std::endl;
    }
    std::cout << "Try programiz.pro";
    for (int i = 0; i < rows; i++)
    {
        delete[] ptr[i];
    }
    delete[] ptr;
    return 0;
}