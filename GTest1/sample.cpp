#include "pch.h"
#include "sample.h"

#include "string"

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
