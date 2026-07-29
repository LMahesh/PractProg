// Online C++ compiler to run C++ program online
/*
#include <iostream>
#include <cstring>
//#define _CRT_SECURE_NO_WARNINGS 1 //included in properties->c++->preprocessor
using namespace std;

char* removestring(const char* str, const char* txt)
{
    char* cpy = (char*)calloc(strlen(str) + 1, 1);
    const char* pos = strstr(str, txt);
    //std::cout << pos << std::endl;
    int len = (int)(pos - str);
    if (!cpy || !pos)
        return NULL;
    //sprintf(cpy, "%.*s", len, str);
    //sprintf(cpy,"%s", pos + strlen(txt));
    sprintf(cpy, "%.*s%s", len, str, pos + strlen(txt));
   // sprintf(cpy + strlen(cpy), "%s", pos + strlen(txt));
 /*   while (pos != nullptr)
    {
        
        pos = strstr(pos, txt);
        pos = pos + strlen(txt);
        if(pos != nullptr)
        sprintf(cpy+strlen(cpy), "%s", pos + strlen(txt));
    }
    */
   //.return cpy;
//}
/*
int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro" << std::endl;

    const char* ptr = "Sri krishna Devaraya University Devaraya University";

    //const char* ptr1 = removestring(ptr, "Devaraya");
    const char* ptr2 = strstr(ptr, "Devaraya");
    while (ptr2 != nullptr)
    {
        ptr2 = strstr(ptr, "Devaraya");
        ptr = ptr2;

        std::cout << ptr2 << std::endl;
    }

    return 0;
}
*/
// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro" << std::endl;

    std::string str = "srikrishna Devaraya University Devaraya University";
    std::string sstr = " ";
    //str.erase(remove(str.begin(),str.end(),'D'),str.end());
    for (string::size_type i = str.find(sstr); i != string::npos; i = str.find(sstr))
        str.erase(i, sstr.length());
    std::cout << str << endl;


    std::string str1 = "Mahesh+Lagisetty+Nandyal";
    for (string::size_type i = str1.find("+"); i != string::npos; i = str1.find("+"))
    {
        str1.erase(i, 1);
    }
    std::cout << str1 << endl;
    return 0;
}
