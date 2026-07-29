// teststring.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// input :2a3b1c output aabbbc
//input 10a      output aaaaaaaaaaa(10 times)
/*
#pragma once

#include "gtest/gtest.h"

#include <iostream>
#include <string>
#include <cstdlib>


using namespace std;



std::string decodeRLE(const std::string& encoded) {
    std::string decoded;
    int n;
    std::string s;
    for (unsigned int i = 0; i < encoded.size(); i++) 
    {
        while (std::isdigit(encoded[i]))
        {
            //string s;
            s = s + encoded[i];
            i++;
        }
        if (std::isalpha(encoded[i])) {
             std::string s1;
             
             

                 for (int j = stoi(s); j > 0; j--) {
                     s1 += encoded[i];
                     
                 }
                 s = "";
                 decoded += s1;
                // i = i + 1;
             }
           //decoded += s1;
           //i = i + 1;
        
    }

    return decoded;
}

int main()
{
    std::string test;
    test = decodeRLE("2a3c4b");
    std::cout << test << std::endl;
    test = decodeRLE("10a12b14c");
    std::cout << test << std::endl;

    
	EXPECT_TRUE("aaaabbbcc",decodeRLE(4a3b2c));
	EXPECT_TRUE(true);

    std::cout << "Hello World!\n";
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
/*
#include <iostream>
using namespace std;
int main()
{
    //Initializing variables.
    char str[100]="prepinsta";
    int i;
    int freq[256] = {0};

    //Calculating frequency of each character.
    for(i = 0; str[i] != '\0'; i++)
    {
        freq[str[i]]++;
    }
    cout<<"The non repeating characters are: ";
    for(i = 0; i < 256; i++)
    {
        if(freq[i] == 1)//Finding non repeating charcters and printing them.
        {
           cout<<char(i)<<"  " ;
        }
    }
    return 0;
}*/


// Online C++ compiler to run C++ program online
#include <iostream>
#include <cstring>
using namespace std;
int substrcnt(char* str, char* substr, int len, int len1)
{
    std::cout << str << " :" << len << substr << " :" << len1;
    int a = 0;
    int cnt = 0;
    for (int i = 0; i < len - len1; i++)
    {
        for (int j = i; j < len1; j++)
        {
            if (str[i + j] == substr[j])
            {
                a++;
                if (a == len1 - 1)
                {
                    cnt++;
                }

            }

        }
    }
    return cnt;

}

int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro";
    char* str = "MaheshMahMaheMahes";
    char* substr = "Mah";
    int len = strlen(str);
    int len1 = strlen(substr);
    int a = substrcnt(str, substr, len, len1);
    std::cout << "substr repeated" << a << "Times" << std::endl;
    return 0;
}