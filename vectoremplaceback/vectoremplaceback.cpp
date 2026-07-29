

// C++ Program to illustrate the high
// cost of copying the elements in
// vector in STL

#include <iostream>
#include <vector>
using namespace std;

// Class
class GFG {

public:
    float x, y;

    // Parameterized Constructor
    GFG(float x, float y)
        : x(x), y(y)
    {
    }

    // Copy Constructor
    GFG(const GFG& GFG)
        : x(GFG.x), y(GFG.y)
    {
        cout << "Copied" << endl;
    }
};

// Driver Code
int main()
{
    // Create an object of vector
    // class object
    vector<GFG> vertices;

    // Reserve the elements in the
    // vector using reserve() method
    vertices.reserve(3);

    // Add element to vector object
    // using emplace_back() method
    vertices.emplace_back(1, 2);
    cout << endl;

    vertices.emplace_back(4, 5);
    cout << endl;

    vertices.emplace_back(7, 8);
    cout << endl;

    for (auto& it : vertices)
        std::cout << it.x << " " << it.y << std::endl;

    return 0;
}