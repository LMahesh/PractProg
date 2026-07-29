#include <iostream>
#include <string>

std::string intoRoman(int num)
{
    int ar[] = { 1,4,5,9,10,40,50,90,100,400,500,900,1000 };
    const char* str[] = { "I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M" };
    
    int cnt = 12;
    std::string str1 = "";
    while (num)
    {
        int div = num / ar[cnt];
        num = num % ar[cnt];
        // std::cout << ar[cnt] << ": " << "" << "cnt" << cnt << "--";
        while (div--)
        {
            //std::cout << "cnt :" << cnt << " ";
            str1 = str1 + str[cnt];

        }
        cnt--;
    }
    std::cout << "roman is:" << str1 << std::endl;
    return str1;
}
int main()
{
    std::cout << "Hello World" << std::endl;
    int a;
    std::cout << "Please Enter a num to convert Roman" << std::endl;
    std::cin >> a;
    std::cout << "Roman for given number is: "<<intoRoman(a) << std::endl;
    return 0;
}