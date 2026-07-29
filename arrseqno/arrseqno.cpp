/******************************************************************************

1--->11--->21----->1211---->111221---->

https://www.geeksforgeeks.org/look-and-say-sequence/
*******************************************************************************/
#include <stdio.h>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

std::string arrseq(int num)
{
    if (num == 1)
        return "1";
    if (num == 2)
        return "11";

    string str = "11";

    for (int i = 3; i <= num; i++)
    {
        str = str + "$";
        int cnt = 1;
        int len = str.size();
        string tmp = "";
        for (int j = 1; j < len; j++)
        {

            if (str[j - 1] != str[j])
            {
                tmp += cnt + '0';
                tmp += str[j - 1];
                cnt = 1;

            }
           else
                cnt++;
        }

        str = tmp;

    }

    return str;


}

int main()
{
    //1---11----21--->1211---->111221

    std::cout << "Hello World" << std::endl;
    std::cout << arrseq(5) << std::endl;

    return 0;
}