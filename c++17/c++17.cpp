#include <iostream>
#include <optional>
#include <variant>
using namespace std;

/* This function can either return an integer value or return nothing */



void varianttest()
{
    std::cout << "----------------variant-----------------------------------------" << std::endl;
    std::variant<int, std::string> var{ 60 }; //This variable can either hold an int or a string, currently it holds an int
    if (var.index() == 0)
    {
        std::cout << get<int>(var) << "\n";
    }
    var = "Hello World!"; //Assigning a string to var
    if (var.index() == 1)
    {
        std::cout << get<std::string>(var) << "\n";
    }
    //The next two lines will cause an error as var can store values of type int or std::string and not float
    /*var = 67.90f;
    std::cout << get<float>(var) <<"\n";*/
}
std::optional<int32_t> parseStringContents(const std::string& str)
{
    std::cout << "-----------------optional<int or>-------------------------------" << std::endl;
    int32_t value = atoi(str.c_str());
    if (value != 0)
    {
        return value; //return value parsed from string
    }
    return std::nullopt; //return nothing
}
int main()
{
    //Positive Scenario
    std::optional<int32_t> x = parseStringContents("45");
    if (x)
    {
        std::cout << *x << "\n";
    }
    else
    {
        std::cout << " Contents of x is not an integer\n";
    }

        //Negative Scenario
   std::optional<int32_t> y = parseStringContents("sd45");
        if (!y)
        {
            std::cout << "Contents of y is not an integer\n";
        }
        else
        {
            std::cout << *y << "\n";
        }
        varianttest();
        return 0;
    
}