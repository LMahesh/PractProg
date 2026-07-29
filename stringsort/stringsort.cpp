#include <string>
#include <iostream>

std::string sort(const std::string& text)
{
    std::string toSort = text;

    for (int i = 0; i < (int)(toSort.size()) - 1; i++)
    {
        if (toSort.at(i) > toSort.at(i + 1))
        {
            char temp = toSort.at(i + 1);
            toSort.at(i + 1) = toSort.at(i);
            toSort.at(i) = temp;
            i = -1;
            //td::cout<<i<<std::endl;
        }
        std::cout << toSort << std::endl;
    }

    std::cout << "Sorted: " << toSort << std::endl;

    return toSort;
}

int main()
{
    //sort("fgfghafbkgdbGHKGHjbkgfnvnbjb14563f");
    sort("X");
    sort("");
    sort("zxv");
    return(0);
}