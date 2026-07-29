// vectorofvector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> solution(vector<vector<string>> queries)
{

    vector<string>vs;
    return vs;

}


int main()
{

    vector<vector<string>>queries = {
        {"ADD", "1"} ,
            {"ADD", "2"},
            {"ADD", "5"},
            {"ADD", "2"},
            {"EXISTS", "2"},
            {"EXISTS", "5"},
            {"EXISTS", "1"},
            {"EXISTS", "4"},
            {"EXISTS", "3"},
            {"EXISTS", "0"}
    };
    /*
    std::vector<string>vs;
    std::vector<string>vs1;
    for (int i = 0; i < queries.size(); i++)
    {
        for (int j = 0; j < queries[i].size(); j++)
        {
            if (queries[i][j] == "ADD")
            {
                if (vs.size() == 0)
                {
                    vs1.push_back(queries[i][j + 1]);
                    vs.push_back("");
                }
                else
                {
                    auto it = find(vs1.begin(), vs1.end(), queries[i][j + 1]);
                    if (it == vs1.end())
                    {
                        vs1.push_back(queries[i][j + 1]);
                        vs.push_back("");

                    }
                    else
                    vs.push_back("");
                }
            }
            if (queries[i][j] == "EXISTS")
            {
                    auto it = find(vs1.begin(), vs1.end(), queries[i][j + 1]);
                    if (it != vs1.end())
                    {
                        vs.push_back("true");
                        vs1.push_back(queries[i][j + 1]);
                    }
                    else
                        vs.push_back("false");
                
            }
            //std::cout << queries[i][j] << " ";
        }
        //std::cout << std::endl;
    }


    for (int i = 0; i < vs.size(); i++)
    {
        std::cout
            << vs[i] << std::endl;
    }

    */
    std::vector<string>vec1;
    std::vector<string>vec2;
    
    for (int i = 0; i < queries.size(); i++)
    {
        for (int j = 0; j < queries[i].size(); j++)
        {
            if (queries[i][j] == "ADD")
            {
                vec1.push_back(queries[i][j + 1]);
                vec2.push_back("NULL");
            }
            if(queries[i][j]== "EXISTS")
            //else
            {
                auto it = find(vec1.begin(), vec1.end(), queries[i][j + 1]);
                if (it != vec1.end())
                {
                    vec2.push_back("true");

                }
                else {
                    //vec1.push_back(queries[i][j + 1]);
                    vec2.push_back("false");
                }

            }

        }
    }
   //return vec2;
   for (int i = 0; i < vec2.size(); i++)
   {
       std::cout
           << vec2[i] << std::endl;
   }

    std::cout << "Hello World!\n";
    return 1;
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
