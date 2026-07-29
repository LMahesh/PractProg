// Online C++ compiler to run C++ program online
#include <iostream>

auto inc = [](int arr[], int len) {
    for (int j = 0; j < len; j++)
        arr[j]++;
    };



auto lambfun = [](int a, int b)->int {return a + b; };


// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void print(std::vector<int>v2)
{

    for_each(v2.begin(), v2.end(), [](int a)
        {
            std::cout << a << endl;
        });
    std::cout << "______________________------------------" << std::endl;
}


int main()
{
    // Write C++ code here
    std::cout << "Try programiz.pro";
    std::cout << "lambda func : "<<lambfun(12, 3) << std::endl;
    int arr[] = { 1,3,5,2,45 };
    int len = sizeof(arr) / sizeof(arr[0]);
    std::cout << "arr size:" << len << std::endl;
    inc(arr, len);
    for (int j = 0; j < len; j++)
        std::cout << arr[j] << " ";

    //lamda expression
    std::vector<int>v1 = { 3,4,6,2,45,1,45,8,37,19 };
    // Write C++ code here
    print(v1);
    sort(v1.begin(), v1.end(), [](const int& a, const int& b)->bool {return a < b; });
    std::cout << "After sort" << std::endl;
    print(v1);
    v1.erase(std::find_if(v1.begin(), v1.end(), [](int i)->bool {return (i == 37); }));
    v1.erase(unique(v1.begin(), v1.end()), v1.end());//remove duplicates
    std::cout << "After remove duplicates" << std::endl;
    print(v1);
    v1.erase(remove_if(v1.begin(), v1.end(), [](int a)->bool {return(a % 2 != 0); }),v1.end());
    print(v1);
    return 1;
}