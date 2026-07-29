// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
int glob_var = 43;
void fun(std::vector<int>* vec1)
{
    for (int i = 0; i < vec1->size(); i++)
        std::cout << vec1->at(i) << std::endl;
}
void func1(int** ptr1)
{
    int a = 6;
    *ptr1 = &a;

}

void func2(int*& rp)

{
    rp = &glob_var;

}
int main() {
    // Write C++ code here
    int arr[] = { 2,4,6,8,23 };
    std::vector<int>vec = { arr,arr + 5 };
    std::cout << "Try programiz.pro" << std::endl;
    fun(&vec);
    std::cout << "________________________________" << std::endl;

    int a = 5;
    int* ptr = &a;
    int& a1 = a;
    func1(&ptr);
    std::cout << *ptr << std::endl;

    func2(ptr);
    std::cout << *ptr << std::endl;
    return 0;
}