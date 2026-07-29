/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
pair<string, int> maxrepstrng(const string& str)
{
    std::cout << "str:" << str << std::endl;
    int n = str.length();
    std::map<string, int>map;


    for (int i = 0; i < n; ++i)
    {
        for (int j = 1; j < n - i; ++j)
        {
            string sstr = str.substr(i, j);
            size_t pos = 0;
            int cnt = 0;

            while ((pos = str.find(sstr, pos)) != string::npos)
            {
                pos = pos + 1;
                cnt = cnt + 1;
            }
            map[sstr] = cnt;
            //std::cout<<"substring: "<<sstr<<" count"<<cnt<<std::endl;
        }

    }

    int maxcnt = 0;
    string sstr1 = "";
    for (auto const& [sstr, cnt] : map)
    {
        if ((maxcnt < cnt) && (sstr.length() > 2))
        {
            maxcnt = cnt;
            sstr1 = sstr;
        }

        //if(sstr1.length() > 4)

        std::cout << "max repeated strng: " << sstr1 << " cnt is:" << maxcnt << std::endl;
    }


    return { sstr1,maxcnt };
}
int main()
{
    std::cout << "Hello World" << std::endl;
    std::string str = "MaheshLagiseMahesLagMahLagLagisettyMahesLagMahes";

    pair<string, int>result = maxrepstrng(str);

    return 0;
}