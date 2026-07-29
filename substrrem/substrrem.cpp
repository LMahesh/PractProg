// Online C++ compiler to run C++ program online
#include <iostream>
#include <cstring>

char* remove(char str[], char substr[])
{
    int len_str = strlen(str);
    int len_substr = strlen(substr);
    std::cout << len_str << " " << len_substr << std::endl;
    std::cout << str << " " << substr << std::endl;
    int i = 0;
    while (i < len_str)
    {
        if (strstr(&str[i], substr) == &str[i])
        {
            len_str = -len_substr;
            for (int j = i; j < len_str; j++)
                str[j] = str[j + len_substr + 1];

        }
        else
            i++;
    }
    str[i] = '\0';
    std::cout << str << std::endl;
    return str;
}
int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro";
    const char* str = "maheshshesh";
    const char* substr = "sh";
    int l = strlen(substr);
    /*
    
     string str1 = str;
    std::cout << "string is " << str << std::endl;
    for (string::size_type i = str1.find("Mah"); i!= string::npos; i = str1.find("Mah"))
    {
        str1.erase(i, 2);
    }
    */
    char str1[l];
    char substr1[strlen(substr)];
    strcpy(str1, str);
    strcpy(substr1, substr);
    str = remove(str1, substr);
    std::cout << str << std::endl;
    return 0;
}   